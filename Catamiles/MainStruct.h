#pragma once

//���� ������Ʈ�� �±��Դϴ�
#define TAG_ENEMY_BULLET 2
#define TAG_BULLET 3

//��� �浹 ���� �̽��� ���Ͽ� �߿��� ����ü���� ���ֽ��ϴ�

//Bresenham �˰����� �̿��ϱ� ���� ����ü�Դϴ�
typedef struct BRESENHAM
{
	int F;
	int dF1;
	int dF2;
} BRESENHAM;

// �ݶ��̴� �浹������ ���� ����մϴ�
typedef struct COLIDER
{
	float start_x;
	float start_y;
	float end_x;
	float end_y;
} COLIDER;

//�Ҽ������ �Ҷ� ����ϴ� POINT ����ü �Դϴ� 
typedef struct VECTOR {
	float x;
	float y;
} VECTOR;

// ���� ������Ʈ�� �ݶ��̴��� ��ġ �׸��� �̹��� ������ ���ϰ� �ֽ��ϴ�
typedef struct GAME_OBJECT
{
	COLIDER colider;
	POINT point;
	int sprite;
	int tag;
} GAME_OBJECT;

//�ִϸ��̼� �ý��ۿ��� ����մϴ�
typedef struct ANIMATION {
	int size;
	int frames[100];
} ANIMATION;

//�ִϸ��̼��� �����Ű������ ����ü�Դϴ�
typedef struct ANIMATION_TASK {
	ANIMATION animation;
	int cursor;
	int timer;
	int length;
} ANIMATION_TASK;

//�Ѿ��� Ÿ�� ����ü�Դϴ�
typedef struct BULLET_TYPE {
	int sprite;
	int spread;
	int speed;
	int cooltime;
	int max;
	int damage;
	int knockback;
	ANIMATION_TASK explode;
} BULLET_TYPE;

//�Ѿ� ����ü �Դϴ�
typedef struct BULLET {
	int id;
	BULLET_TYPE type;
	POINT startPoint;
	VECTOR direction;
	int cooltime;
	COLIDER colider;
	int tag;
	VECTOR point;
} BULLET;

//�� ����ü �Դϴ�
typedef struct GUN {
	BULLET_TYPE type;
	int image;
	int sprite;
	int clip;
	int cooltime;
	char * sound;
} GUN;

//�� ������ ����� ���� ���� ����ü�Դϴ�
typedef struct STATE {
	int type;
	int length;
} STATE;

//���� �ൿ�ϱ� ���� ����ϴ� ����ü�Դϴ�
typedef struct STATE_TASK {
	STATE state;
	int timer;
} STATE_TASK;

//���� �ൿ������ ����ִ� ����ü�Դϴ�
typedef struct STATE_PATTERN {
	int size;
	int cursor;
	STATE_TASK states[20];
} STATE_PATTERN;

//���� Ÿ���� �����ϴ� ����ü�Դϴ�
typedef struct ENEMY_TYPE {
	int type;
	int health_point;
	GUN gun;

	ANIMATION_TASK ani_hited_task;
	ANIMATION_TASK ani_idle_task;
	ANIMATION_TASK ani_death_task;
} ENEMY_TYPE;

//�������� ������ ����ִ� ����ü�Դϴ�
typedef struct ITEM
{
	int type;
	int sprite;
}ITEM;

//���� ������Ʈ�� ����ϱ����� ����ü�Դϴ�
typedef struct ENEMY {
	COLIDER colider;
	POINT point;
	int sprite;
	STATE_PATTERN state;
	ENEMY_TYPE type;
} ENEMY;

//�κ��丮�� ������ ����ִ� ����ü�Դϴ�
typedef struct INVENTORY {
	int e_blank[3];
	GUN equipGun[3];
	int invSize;
	GUN invGun[8];
	int invItemSize;
	ITEM invItem[8];
} INVENTORY;

//ArrayList ����ü�Դϴ�
typedef struct ArrayList {
	int size;
	GAME_OBJECT game_list[100];
	BULLET bullet_list[100];
	ENEMY enemy_list[100];
	COLIDER colider_list[100];
} ArrayList;