#include <iostream>
#include <fstream>
#include <Windows.h>
#include <memory>
#pragma pack(2)

using namespace std;

// 用于存储32位的像素点
struct rgba
{
	char b;
	char g;
	char r;
	char a;
};
// 用于存储24位的像素点
struct rgb
{
	char b;
	char g;
	char r;
};
// 位图数据基类
class picdata
{
public:
	int width, height;
	picdata(int width, int height) : width(width), height(height) { ; }
	virtual void read(ifstream &in) = 0;
	virtual void write(ofstream &out) = 0;
	virtual void rotate(int degree = 90) = 0;
	virtual ~picdata()
	{
		;
	}
};
// 24位位图数据类
class data24 : public picdata
{
	/*
		24位读写时要判断每一行数据是否为4字节对齐，否则扔掉多余的0或写入0来补位
		32位因为一个像素正好是一个字节，所以不存在这个问题
	*/
private:
	rgb * data;
public:
	data24(int width, int height) :picdata(width, height)
	{
		data = new rgb[width * height];
	}
	data24(const data24 & other) :picdata(other.width, other.height)
	{
		data = new rgb[width * height];
		memcpy(data, other.data, sizeof(rgb) * width * height);
	}
	virtual void read(ifstream &in)
	{
		char temp[3];
		for (int i = 0; i < height; ++i)
		{
			in.read((char *)(data + i * width), sizeof(rgb) * width);
			int leftbyte = (24 * width + 31) / 32 * 4 - sizeof(rgb) * width;
			if (leftbyte)
				in.read(temp, leftbyte);
		}
	}
	virtual void write(ofstream &out)
	{
		for (int i = 0; i < height; ++i)
		{
			char temp[3] = "\0\0";
			out.write((char *)(data + i * width), sizeof(rgb) * width);
			int leftbyte = (24 * width + 31) / 32 * 4 - sizeof(rgb) * width;
			if (leftbyte)
				out.write(temp, leftbyte);
		}
	}
	rgb *operator[](int x)
	{
		return data + x * width;
	}
	virtual void rotate(int degree = 90)
	{
		data24 temp(*this);
		height = temp.width;
		width = temp.height;
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				(*this)[i][j] = temp[j][height - i - 1];
			}
		}
	}
	~data24()
	{
		if (data)
			delete[]data;
	}
};
// 32位位图数据类
class data32 : public picdata
{
private:
	rgba * data;
public:
	data32(int width, int height) :picdata(width, height)
	{
		data = new rgba[width * height];
	}
	data32(const data32 & other) :picdata(other.width, other.height)
	{
		data = new rgba[width * height];
		memcpy(data, other.data, sizeof(rgba) * width * height);
	}
	virtual void read(ifstream &in)
	{
		for (int i = 0; i < height; ++i)
		{
			in.read((char *)(data + i * width), sizeof(rgba) * width);
		}
	}
	virtual void write(ofstream &out)
	{
		for (int i = 0; i < height; ++i)
		{
			out.write((char *)(data + i * width), sizeof(rgba) * width);
		}
	}
	rgba *operator[](int x)
	{
		return data + x * width;
	}
	virtual void rotate(int degree = 90)
	{
		data32 temp(*this);
		height = temp.width;
		width = temp.height;
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				(*this)[i][j] = temp[j][height - i - 1];
			}
		}
	}
	~data32()
	{
		if (data)
			delete[]data;
	}
};

// 文件数据类
class pictureData
{
	/*
	因为位图信息数据结构可能不一样，所以选用最大的BITMAPV5HEADER结构，并用一个变量来区别不同的数据结构。
	例如：加入位图信息数据为40字节的BITMAPINFOHEAR，就只用BITMAPV5HEADER的前40字节——正好跟BITMAPINFOHEAR的成员一一对应
	在读文件的时候先读入infosize，然后进行判断接下来需要读的字节数
	在写文件的时候只写infosize大小的数据
	*/
private:
	BITMAPFILEHEADER fileheader; // 位图头文件数据
	BITMAPV5HEADER infoheader; // 位图信息数据
	
	unsigned long infosize; // infoheader大小
	picdata *picture; // 位图数据 
public:
	pictureData() { picture = NULL; }
	pictureData(const pictureData &pic)
	{
		if (pic.infoheader.bV5BitCount == 24)
		{
			picture = new data24(pic.picture->width, pic.picture->height);
			memcpy(picture, pic.picture, sizeof(data24));
		}
		else
		{
			picture = new data32(pic.picture->width, pic.picture->height);
			memcpy(picture, pic.picture, sizeof(data32));
		}
	}
	~pictureData()
	{
		if (picture)
			delete picture;
	}
	pictureData &operator=(pictureData &pic)
	{
		if (this == &pic)
			return *this;
		if (picture)
			delete[] picture;
		fileheader = pic.fileheader;
		infoheader = pic.infoheader;
		infosize = pic.infosize;
		if (pic.infoheader.bV5BitCount == 24)
		{
			picture = new data24(pic.picture->width, pic.picture->height);
			memcpy(picture, pic.picture, sizeof(rgb) * picture->width * picture->height);
		}
		else
		{
			picture = new data32(pic.picture->width, pic.picture->height);
			memcpy(picture, pic.picture, sizeof(rgba) * picture->width * picture->height);
		}
		return *this;
	}
	void read(ifstream &in)
	{
		in.read((char *)&fileheader, sizeof(fileheader));
		in.read((char *)&infosize, sizeof(infosize));
		infoheader.bV5Size = infosize;
		in.read(((char *)&infoheader) + sizeof(infosize), infosize - sizeof(infosize));
		if (picture)
			delete[]picture;
		if (infoheader.bV5BitCount == 24)
			picture = new data24(infoheader.bV5Width, infoheader.bV5Height);
		else
			picture = new data32(infoheader.bV5Width, infoheader.bV5Height);
		picture->read(in);
	}
	void write(ofstream &out)
	{
		out.write((char *)&fileheader, sizeof(fileheader));
		out.write((char *)&infoheader, infoheader.bV5Size);
		picture->write(out);
	}
	void rotate(int degree = 90)
	{
		if (degree == 90)
		{
			picture->rotate(degree);
			infoheader.bV5Width = picture->width;
			infoheader.bV5Height = picture->height;
			long temp = infoheader.bV5XPelsPerMeter;
			infoheader.bV5XPelsPerMeter = infoheader.bV5YPelsPerMeter;
			infoheader.bV5YPelsPerMeter = temp;
			infoheader.bV5SizeImage = (infoheader.bV5BitCount * picture->width + 31) / 32 * 4 * picture->height;
			fileheader.bfSize = fileheader.bfOffBits + infoheader.bV5SizeImage;
		}
		else if (degree == 180)
		{
			rotate(degree = 90);
			rotate(degree = 90);
		}
		else if (degree == 270)
		{
			rotate(degree = 90);
			rotate(degree = 90);
			rotate(degree = 90);
		}
	}
};

int main(int argc, const char *argv[])
{
	if (argc < 3) // 参数数量检验
	{
		cout << "参数数量错误" << endl;
		cout << "请输入: " << argv[0] << " input_name output_name" << endl;
		return -1;
	}
	ifstream fin(argv[1], ios::in | ios::binary);
	if (!fin) // 打开文件检验
	{
		cout << argv[1] << "文件打开失败" << endl;
		return -1;
	}
	ofstream fout(argv[2], ios::out | ios::binary);
	if (!fout) // 打开文件检验
	{
		fin.close();
		cout << argv[2] << "文件打开失败" << endl;
		return -1;
	}

	pictureData pic;

	pic.read(fin); // 读文件
	pic.rotate(90); // 旋转
	pic.write(fout); // 写文件

	// 关闭文件
	fin.close();
	fout.close();
	return 0;
}