#pragma once

//���ӿ� ���������� ���Ǵ� ArrayList ���� �Լ����Դϴ�
//�⺻���� add�� remove�� �����մϴ�

//�ڷ��� ���� �Լ��� �������� �ֽ��ϴ�

//��� ����Ʈ�� �ʱ�ȭ�ϴ� �Լ� �Դϴ�.
void initList(ArrayList* list)
{
	list->size = 0;
}

// ArrayList GAME_OBJECT
int addGameObjectItem(ArrayList* list, GAME_OBJECT gameObject)
{
	list->game_list[list->size] = gameObject;
	list->size++;
	return list->size - 1;
}

int removeGameObjectItem(ArrayList* list, int index)
{
	for (int i = index; i < list->size; i++)
	{
		list->game_list[i] = list->game_list[i + 1];
	}
	list->size--;

	return 0;
}

GAME_OBJECT getGameObjectItem(ArrayList* list, int index)
{
	if (index <= list->size)
		return list->game_list[index];
}
// ArrayList GAME_OBJECT

// ArrayList BULLET
int addBulletItem(ArrayList * list, BULLET bullet)
{
	list->bullet_list[list->size] = bullet;
	list->size++;

	return list->size - 1;
}

void removeBulletItem(ArrayList * list, int index)
{
	for (int i = index; i < list->size; i++)
	{
		list->bullet_list[i] = list->bullet_list[i + 1];
		list->bullet_list[i].id -= 1;
	}
	list->size--;
}

BULLET getBulletItem(ArrayList * list, int index)
{
	if (index <= list->size)
		return list->bullet_list[index];
}
// ArrayList BULLET

// ArrayList ENEMY
int addEnemyItem(ArrayList* list, ENEMY enemy)
{
	list->enemy_list[list->size] = enemy;
	list->size++;
	return list->size - 1;
}

int removeEnemyItem(ArrayList* list, int index)
{
	for (int i = index; i < list->size; i++)
	{
		list->enemy_list[i] = list->enemy_list[i + 1];
	}
	list->size--;

	return 0;
}

ENEMY getEnemyItem(ArrayList* list, int index)
{
	if (index <= list->size)
		return list->enemy_list[index];
}
// ArrayList ENEMY

// ArrayList COLIDER
int addColiderItem(ArrayList* list, COLIDER colider)
{
	list->colider_list[list->size] = colider;
	list->size++;
	return list->size - 1;
}

int removeColiderItem(ArrayList* list, int index)
{
	for (int i = index; i < list->size; i++)
	{
		list->colider_list[i] = list->colider_list[i + 1];
	}
	list->size--;

	return 0;
}

COLIDER getColiderItem(ArrayList* list, int index)
{
	if (index <= list->size)
		return list->colider_list[index];
}
// ArrayList COLIDER