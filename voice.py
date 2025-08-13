import serial
import speech_recognition as sr
import time
# Set the correct COM port (check Device Manager for your actual port)
ser = serial.Serial('COM13', 9600, timeout=1)
recognizer = sr.Recognizer()
mic = sr.Microphone()
print("Listening for #START signal from Arduino...")
while True:
if ser.in_waiting:
line = ser.readline().decode(errors='ignore').strip()
print("Arduino says:", line)
if "#START" in line:
print("Button pressed! Recording voice...")
with mic as source:
recognizer.adjust_for_ambient_noise(source)
audio = recognizer.listen(source)
try:
text = recognizer.recognize_google(audio)
print(f"Recognized: {text}")
# Send each letter to Arduino (ignore spaces, non-alphabet)
for char in text:
if char.isalpha():
ser.write(char.upper().encode())
print(f"Sent: {char.upper()}")
time.sleep(1) # Allow Arduino to process one letter at a time
except sr.UnknownValueError:
print("Could not understand the audio.")
except sr.RequestError:
print("API unavailable or connection error.")
