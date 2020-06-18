#pragma once

void RemoveTask_NonExistentTask_ThrowsException();
void RemoveTask_ValidTask_TaskRemoved();
void StartTask_NonExistentTask_ThrowsException();
void StartTask_ValidTask_TaskStarted();
void DoneTask_NonExistentTask_ThrowsException();
void DoneTask_ValidTask_TaskDone();