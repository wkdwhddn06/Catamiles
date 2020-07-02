#pragma once

//�з��ϱ� �����ϰų�, ���Ŀ� �������� �ʾƵ� �Ǵ� �Լ����� ���ֽ��ϴ�

//Ŀ�� ����
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

//Ŀ���� ����� �Լ��Դϴ�
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

//��Ʈ���� ����� ���ϴ� �Լ��Դϴ�
POINT getBitmapSize(HINSTANCE hInst, int bitmap)
{
	BITMAP Bitmap;
	HBITMAP hbit = LoadBitmap(hInst, MAKEINTRESOURCE(bitmap));
	GetObject(hbit, sizeof(BITMAP), &Bitmap);
	POINT size = {Bitmap.bmWidth,Bitmap.bmHeight};
	DeleteObject(hbit);
	return size;
}

//��Ʈ���� COLIDER�� ������ִ� �Լ��Դϴ�
COLIDER getColider(HINSTANCE hInst, POINT point, int bitmap)
{
	BITMAP Bitmap;
	HBITMAP hbit = LoadBitmap(hInst, MAKEINTRESOURCE(bitmap));
	GetObject(hbit, sizeof(BITMAP), &Bitmap);
	POINT size = { Bitmap.bmWidth,Bitmap.bmHeight };
	COLIDER colider = { point.x, point.y, point.x + size.x, point.y + size.y };
	DeleteObject(hbit);
	return colider;
}

//������Ʈ�� ȭ�� ������ �������� üũ�ϴ� �Լ��Դϴ�
int isObjectOutWindow(POINT point, POINT s_size)
{
	if ((point.x > s_size.x || point.y > s_size.y) || (point.x < 0 || point.y < 0))
		return 1;
	else
		return 0;
}

VECTOR toVector(POINT a)
{
	VECTOR tmp;
	tmp.x = a.x;
	tmp.y = a.y;
	return tmp;
}

//���� �׽�Ʈ ��
int random(int min, int max)
{
	max += 1;
	int a = (rand() % (max - min)) + min;
	return a;
}

//�̸��� �̷��� ����ϱ� ���ϱ� �����Դϴ�, ����Ʈ�� ����� �Լ��Դϴ�
POINT cp(int a, int b)
{
	POINT tmp;
	tmp.x = a;
	tmp.y = b;
	return tmp;
}

POINT addPoint(POINT a, POINT b)
{
	POINT tmp;
	tmp.x = a.x + b.x;
	tmp.y = a.y + b.y;
	return tmp;
}

POINT subtractPoint(POINT a, POINT b)
{
	POINT tmp;
	tmp.x = a.x - b.x;
	tmp.y = a.y - b.y;
	return tmp;
}

COLIDER addPointToColider(COLIDER col, POINT a)
{
	col.start_x += a.x;
	col.end_x += a.x;
	col.start_y += a.y;
	col.end_y += a.y;
	return col;
}