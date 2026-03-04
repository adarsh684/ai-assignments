# Turing Test Implementation

## Overview

The **Turing Test**, proposed by Alan Turing, is used to determine whether a machine can exhibit intelligent behavior similar to a human.

In this test, a **human judge interacts with both a human and a machine through a conversation interface**.
If the judge cannot reliably distinguish the machine from the human, the machine is considered to have passed the Turing Test.

---

## Architecture

### 1. Human Judge

The judge asks questions to both participants and evaluates their responses.

### 2. Conversation Interface

Acts as the communication medium between the judge and participants.
It ensures that the judge does not know whether the response is from a human or a machine.

### 3. Human Participant

A real human providing natural responses.

### 4. AI Agent

A program that generates responses designed to imitate human behavior.

### 5. Decision 

The judge analyzes the responses and decides which participant is the machine.

---

## Working Process

1. The judge enters a question.
2. The system forwards the question to both the human and the AI.
3. Both participants generate responses.
4. The responses are shown to the judge anonymously.
5. The judge attempts to identify the machine.

If the judge cannot distinguish them reliably, the AI is said to pass the test.

---

## Purpose

The Turing Test is used to evaluate **machine intelligence and human-like behavior in artificial intelligence systems**.

(I could not implement a real turing test in terminal, so this is a program which tries to seem human with it's replies) 

