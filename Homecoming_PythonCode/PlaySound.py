import time
from pygame import mixer

mixer.init()
electric=mixer.Sound('electric.wav')
applause=mixer.Sound('applause.wav')

while True:
    applause.play()
    #sleep the time of the applause audio
    time.sleep(7);
    electric.play()
    #sleep the time of the electric audio
    time.sleep(10);
    