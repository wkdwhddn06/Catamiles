#pragma once

ANIMATION createAnimation(int args, ...)
{
	ANIMATION animation;
	va_list ap;
	
	va_start(ap, args);

	for (int i = 0; i < args; i++)    // ���� ���� ������ŭ �ݺ�
	{
		int num = va_arg(ap, int);    // int ũ�⸸ŭ ���� ���� ��� �����Ϳ��� ���� ������
									  // ap�� int ũ�⸸ŭ ���������� �̵�
		animation.frames[i] = num;    // ���� ���� �� ���
	}
	va_end(ap);

	animation.size = args;
	return animation;
}

ANIMATION_TASK createAnimationTask(ANIMATION ani, int length)
{
	ANIMATION_TASK task;
	task.animation = ani;
	task.cursor = 0;
	task.length = length;
	task.timer = 0;
	return task;
}

int isAnimationStarted(ANIMATION_TASK task)
{
	if (task.timer != 0)
		return 1;
	else if (task.cursor != 0)
		return 1;

	return 0;
}

int showAnimation(ANIMATION_TASK * task)
{
	if (task->cursor < task->animation.size-1)
	{
		if (task->timer == task->length)
		{
			task->cursor += 1;
			task->timer = 0;
		}
		task->timer += 1;
		return task->animation.frames[task->cursor];
	}
	else
		return 1;
}