# 矩阵乘法
import tensorflow as tf
import numpy as np

# 生成随机数据
_x = np.random.rand(100).astype(np.float32)
y_data = _x*0.1 + 0.3
x_data = np.matrix([_x, np.ones([100])]).astype(np.float32)

# 创建tensorflow结构
theta = tf.Variable(tf.random_uniform([2, 1], -1, 1))
y = tf.matmul(tf.transpose(theta), x_data)

loss = tf.reduce_mean(tf.square(y-y_data))
optimizer = tf.train.GradientDescentOptimizer(0.5)
train = optimizer.minimize(loss)

init = tf.global_variables_initializer() # 初始化
sess = tf.Session()
sess.run(init)


for step in range(401):
    sess.run(train)
    if step % 40 == 0:
        print(step, sess.run(theta))
