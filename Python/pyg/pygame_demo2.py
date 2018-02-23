import pygame
import sys

pygame.init()
print(pygame.display.Info())
size = width, height = 600, 400
screen = pygame.display.set_mode(size, )
pygame.display.set_caption("pygame")

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    pygame.display.update()
