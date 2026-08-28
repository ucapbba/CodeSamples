#pragma once

// ============================================================================
// LambdaLesson.h
//
// A self-contained set of lessons that walk through lambdas step by step,
// ending with the exact "lazy static cache" pattern used in the Athene
// codebase:
//
//      static const auto cache = []() { ... }();
//
// See LambdaLesson.cpp for the implementation of each lesson.
// Call RunLambdaLesson() from main() to run them all in order.
// ============================================================================

void Lesson1_BasicLambdaSyntax();
void Lesson2_Captures();
void Lesson3_LambdasAsAlgorithmCallbacks();
void Lesson4_ImmediatelyInvokedLambda();
void Lesson5_LazyStaticCachePattern();

// Runs all lessons in order, with a banner before/after.
void RunLambdaLesson();
