# CAPTCHA System

## Overview

CAPTCHA stands for:

**Completely Automated Public Turing Test to Tell Computers and Humans Apart**

It is a security mechanism used by websites to distinguish **human users from automated bots**.

CAPTCHA systems present a challenge that is easy for humans but difficult for automated programs to solve.

---

## Architecture

### 1. CAPTCHA Generator

Creates a random challenge such as numbers, letters, or images.

### 2. Challenge Display

Displays the CAPTCHA challenge to the user.

### 3. User Input

The user enters the characters or solves the challenge.

### 4. Verification Module

The system checks whether the user input matches the generated CAPTCHA.

### 5. Decision

Based on verification, the system allows or denies access.

---

## Working Process

1. The system generates a random CAPTCHA challenge.
2. The challenge is displayed to the user.
3. The user enters the solution.
4. The system verifies the input.
5. If correct, access is granted; otherwise, the user must try again.

---

## Purpose

CAPTCHA systems are used to prevent:

* Automated bots
* Spam submissions
* Fake account creation
* Website abuse

They help ensure that **only human users interact with web services**.

