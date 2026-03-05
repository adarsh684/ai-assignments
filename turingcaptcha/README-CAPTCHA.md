# CAPTCHA 

## Description

CAPTCHA (Completely Automated Public Turing test to tell Computers and Humans Apart) is used to distinguish human users from automated bots.

This implementation:

* Generates a **random alphanumeric CAPTCHA**
* Uses **ASCII distortion using the ****`toilet`**** library**
* Allows limited attempts to solve the CAPTCHA
* Grants or denies access based on verification

## Features

* Random CAPTCHA generation
* Distorted ASCII text display
* Multiple attempt verification
* Basic security mechanism

---

## CAPTCHA Architecture

User
↓
CAPTCHA Generator
↓
Distortion Module (toilet ASCII library)
↓
Display CAPTCHA
↓
User Input
↓
Verification Engine
↓
Access Granted / Access Denied

---

# Requirements

* C Compiler (GCC / Clang)
* Linux / macOS terminal
* `toilet` ASCII art generator

Install toilet (Linux):

sudo apt install toilet


Install toilet (macOS):

brew install toilet
