import pygame
from pygame.locals import *
import online
import table
from sys import exit

screen_size = (1024, 600)

background_image_filename = 'shuimohua-018.jpg'

def main():
    pygame.init()
    screen = pygame.display.set_mode(screen_size, 0, 32)
    background = pygame.image.load(background_image_filename).convert()
    background = pygame.transform.scale(background, screen_size)
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                exit()
        
        screen.blit(background, (0,0))

        pygame.display.update()


if __name__ == '__main__':
    main()