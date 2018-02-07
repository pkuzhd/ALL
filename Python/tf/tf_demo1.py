# 梯度下降法
import tensorflow as tf
import numpy as np

# 生成随机数据
x_data = np.random.rand(100).astype(np.float32)
y_data = x_data*0.1 + 0.3


# 创建tensorflow结构
Weights = tf.Variable(tf.random_uniform([1], -1, 1))
biases = tf.Variable(tf.zeros([1]))

y = Weights*x_data + biases

loss = tf.reduce_mean(tf.square(y-y_data))

optimizer = tf.train.GradientDescentOptimizer(0.5)
train = optimizer.minimize(loss)

init = tf.global_variables_initializer() # 初始化

sess = tf.Session()
sess.run(init)

for step in range(401):
    sess.run(train)
    if step % 40 == 0:
        print(step, sess.run(Weights), sess.run(biases))
