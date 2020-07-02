#pragma once

//������ ��밡 �Ǵ� ����, �浹���� �ý����� ����ϴ� ����Դϴ�

//���̿� ������ TRUE ��ȯ
#define BETWEEN(a,b,c) ((a <= b)&&(b <= c))

//�浹ó�� ����
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//�浹 ������ �����ϱ����� ����ü�Դϴ�
typedef struct COLIDE_INFO
{
	int isColide;
	BULLET bullet;
	int tag;
} COLIDE_INFO;

//�ݶ��̴��� �Բ� ������Ʈ�� �̵���ŵ�ϴ�(���� ������)
void MoveWithColider(GAME_OBJECT* obj, POINT v)
{
	obj->point.x += v.x;
	obj->point.y += v.y;

	obj->colider.end_x += v.x;
	obj->colider.end_y += v.y;
	obj->colider.start_x += v.x;
	obj->colider.start_y += v.y;
}

int isColide(COLIDER a, COLIDER b)
{
	const int isInSameX = (BETWEEN(a.start_x, b.start_x, a.end_x) || BETWEEN(a.start_x, b.end_x, a.end_x));
	const int isInSameY = (BETWEEN(a.start_y, b.start_y, a.end_y) || BETWEEN(a.start_y, b.end_y, a.end_y));

	if (isInSameX)
	{
		if (BETWEEN(a.start_y, b.start_y, a.end_y))
			return 0;
		else if (BETWEEN(a.start_y, b.end_y, a.end_y))
			return 0;
	}

	else if (isInSameY)
	{
		if (BETWEEN(a.start_y, b.start_y, a.end_y))
			return 0;
		else if (BETWEEN(a.start_y, b.end_y, a.end_y))
			return 0;
	}
	else
		return 1;
}

//�浹 ó�� �Լ��� �Դϴ�
int isColideForBullet(COLIDER player, ArrayList * pool, ArrayList * enemy)
{
	for (int i = 0; i < enemy->size; i++)
	{
		COLIDER colider = enemy->enemy_list[i].colider;
		const int isInSameX = (BETWEEN(colider.start_x, player.start_x, colider.end_x) || BETWEEN(colider.start_x, player.end_x, colider.end_x));
		const int isInSameY = (BETWEEN(colider.start_y, player.start_y, colider.end_y) || BETWEEN(colider.start_y, player.end_y, colider.end_y));

		if (isInSameX && BETWEEN(colider.start_y, player.start_y, colider.end_y))
		{
			return 0;
		}
		else if (isInSameX && BETWEEN(colider.start_y, player.end_y, colider.end_y))
		{
			return 0;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player.start_x, colider.end_x))
		{
			return 0;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player.end_x, colider.end_x))
		{
			return 0;
		}
	}

	return 1;
}

int isColideWithMoving(GAME_OBJECT * player, POINT nextMove, ArrayList* coliders)
{
	for (int i = 0; i < coliders->size; i++)
	{
		COLIDER colider = coliders->colider_list[i];
		COLIDER player_col = addPointToColider(player->colider, nextMove);
		const int isInSameX = (BETWEEN(colider.start_x, player_col.start_x, colider.end_x) || BETWEEN(colider.start_x, player_col.end_x, colider.end_x));
		const int isInSameY = (BETWEEN(colider.start_y, player_col.start_y, colider.end_y) || BETWEEN(colider.start_y, player_col.end_y, colider.end_y));

		if (isInSameX && BETWEEN(colider.start_y, player_col.start_y, colider.end_y))
		{
			//���� �鿡 �������
			return 0;
		}
	    else if (isInSameX && BETWEEN(colider.start_y, player_col.end_y, colider.end_y))
		{
			//�Ʒ��� �鿡 �������
			return 0;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player_col.start_x, colider.end_x))
		{
			//���� �鿡 �������
			return 0;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player_col.end_x, colider.end_x))
		{
			//������ �鿡 �������
			return 0;
		}
	}

	return 1;
}

int isColideWithColiders(COLIDER player, ArrayList* coliders)
{
	for (int i = 0; i < coliders->size; i++)
	{
		COLIDER colider = coliders->colider_list[i];
		const int isInSameX = (BETWEEN(colider.start_x, player.start_x, colider.end_x) || BETWEEN(colider.start_x, player.end_x, colider.end_x));
		const int isInSameY = (BETWEEN(colider.start_y, player.start_y, colider.end_y) || BETWEEN(colider.start_y, player.end_y, colider.end_y));

		if (isInSameX && BETWEEN(colider.start_y, player.start_y, colider.end_y))
		{
			return 0;
		}
		else if (isInSameX && BETWEEN(colider.start_y, player.end_y, colider.end_y))
		{
			return 0;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player.start_x, colider.end_x))
		{
			return 0;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player.end_x, colider.end_x))
		{
			return 0;
		}
	}

	return 1;
}

int isColideForMath(COLIDER player, COLIDER colider)
{
	const int isInSameX = (BETWEEN(colider.start_x, player.start_x, colider.end_x) || BETWEEN(colider.start_x, player.end_x, colider.end_x));
	const int isInSameY = (BETWEEN(colider.start_y, player.start_y, colider.end_y) || BETWEEN(colider.start_y, player.end_y, colider.end_y));

	if (isInSameX && BETWEEN(colider.start_y, player.start_y, colider.end_y))
	{
		return 0;
	}
	else if (isInSameX && BETWEEN(colider.start_y, player.end_y, colider.end_y))
	{
		return 0;
	}
	else if (isInSameY && BETWEEN(colider.start_x, player.start_x, colider.end_x))
	{
		return 0;
	}
	else if (isInSameY && BETWEEN(colider.start_x, player.end_x, colider.end_x))
	{
		return 0;
	}

	return 1;
}

//���� ���� �浹 ó�� �Լ��Դϴ�
COLIDE_INFO isColideForEnemy(COLIDER colider, ArrayList* pool)
{
	COLIDE_INFO info;
	for (int i = 0; i < pool->size; i++)
	{
		if (pool->bullet_list[i].tag == TAG_BULLET)
		{
			COLIDER player = pool->bullet_list[i].colider;
			const int isInSameX = (BETWEEN(colider.start_x, player.start_x, colider.end_x) || BETWEEN(colider.start_x, player.end_x, colider.end_x));
			const int isInSameY = (BETWEEN(colider.start_y, player.start_y, colider.end_y) || BETWEEN(colider.start_y, player.end_y, colider.end_y));

			if (isInSameX && BETWEEN(colider.start_y, player.start_y, colider.end_y))
			{
				info.isColide = 1;
				info.bullet = pool->bullet_list[i];
				return info;
			}
			else if (isInSameX && BETWEEN(colider.start_y, player.end_y, colider.end_y))
			{
				info.isColide = 2;
				info.bullet = pool->bullet_list[i];
				return info;
			}
			else if (isInSameY && BETWEEN(colider.start_x, player.start_x, colider.end_x))
			{
				info.isColide = 3;
				info.bullet = pool->bullet_list[i];
				return info;
			}
			else if (isInSameY && BETWEEN(colider.start_x, player.end_x, colider.end_x))
			{
				info.isColide = 4;
				info.bullet = pool->bullet_list[i];
				return info;
			}
		}
	}
	info.isColide = 0;
	return info;
}

//�÷��̾ ���� �浹 ó�� �Լ��Դϴ�
COLIDE_INFO isColideForPlayerAndBullet(COLIDER colider, ArrayList* pool, ArrayList* enemy)
{
	COLIDE_INFO info;
	for (int i = 0; i < pool->size; i++)
	{
		if (pool->bullet_list[i].tag == TAG_ENEMY_BULLET)
		{
			COLIDER player = pool->bullet_list[i].colider;
			const int isInSameX = (BETWEEN(colider.start_x, player.start_x, colider.end_x) || BETWEEN(colider.start_x, player.end_x, colider.end_x));
			const int isInSameY = (BETWEEN(colider.start_y, player.start_y, colider.end_y) || BETWEEN(colider.start_y, player.end_y, colider.end_y));

			if (isInSameX && BETWEEN(colider.start_y, player.start_y, colider.end_y))
			{
				info.isColide = 1;
				info.bullet = pool->bullet_list[i];
				return info;
			}
			else if (isInSameX && BETWEEN(colider.start_y, player.end_y, colider.end_y))
			{
				info.isColide = 2;
				info.bullet = pool->bullet_list[i];
				return info;
			}
			else if (isInSameY && BETWEEN(colider.start_x, player.start_x, colider.end_x))
			{
				info.isColide = 3;
				info.bullet = pool->bullet_list[i];
				return info;
			}
			else if (isInSameY && BETWEEN(colider.start_x, player.end_x, colider.end_x))
			{
				info.isColide = 4;
				info.bullet = pool->bullet_list[i];
				return info;
			}
		}
	}

	for (int i = 0; i < enemy->size; i++)
	{
		COLIDER player = enemy->enemy_list[i].colider;
		const int isInSameX = (BETWEEN(colider.start_x, player.start_x, colider.end_x) || BETWEEN(colider.start_x, player.end_x, colider.end_x));
		const int isInSameY = (BETWEEN(colider.start_y, player.start_y, colider.end_y) || BETWEEN(colider.start_y, player.end_y, colider.end_y));

		if (isInSameX && BETWEEN(colider.start_y, player.start_y, colider.end_y))
		{
			info.isColide = 1;
			return info;
		}
		else if (isInSameX && BETWEEN(colider.start_y, player.end_y, colider.end_y))
		{
			info.isColide = 2;
			return info;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player.start_x, colider.end_x))
		{
			info.isColide = 3;
			return info;
		}
		else if (isInSameY && BETWEEN(colider.start_x, player.end_x, colider.end_x))
		{
			info.isColide = 4;
			return info;
		}
	}
	info.isColide = 0;
	return info;
}

//���������� ����Ͽ� ������Ʈ�� �̵���ŵ�ϴ�
void Lerp(GAME_OBJECT* target, POINT destination,int speed)
{
	LONG x = target->point.x;
	LONG y = target->point.y;

	LONG dx = destination.x;
	LONG dy = destination.y;

	target->point.x += (dx - x) * (0.016 * speed);
	target->point.y += (dy - y) * (0.016 * speed);
}

//�������� ���� ���ϴ� �Լ� �Դϴ�
POINT LerpForMath(POINT start, POINT destination, int speed)
{
	LONG x = start.x;
	LONG y = start.y;

	LONG dx = destination.x;
	LONG dy = destination.y;

	POINT tmp;
	tmp.x = (dx - x) * (speed);
	tmp.y = (dy - y) * (speed);

	return tmp;
}

//���������� ����Ͽ� ����Ʈ�� �̵���ŵ�ϴ�
POINT LerpPoint(POINT target, POINT destination, int speed)
{
	POINT tmp = target;

	LONG x = target.x;
	LONG y = target.y;

	LONG dx = destination.x;
	LONG dy = destination.y;

	tmp.x += (dx - x) * (0.016 * speed);
	tmp.y += (dy - y) * (0.016 * speed);

	return tmp;
}

//���� ���������Դϴ�
void LerpForEnemy(ENEMY* target, POINT destination, int speed)
{
	LONG x = target->point.x;
	LONG y = target->point.y;

	LONG dx = destination.x;
	LONG dy = destination.y;

	target->point.x += (dx - x) * (0.016 * speed);
	target->point.y += (dy - y) * (0.016 * speed);
}

//�Ϲ����� �̵� �Լ� �Դϴ�
POINT MoveForward(POINT target, POINT d, int speed)
{
	LONG x = target.x;
	LONG y = target.y;	

	POINT res;
	POINT direction;
	direction.x = (d.x - x);
	direction.y = (d.y - y);

	double length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	double movement_direction_normalized_x = (double)direction.x / length;
	double movement_direction_normalized_y = (double)direction.y / length;

	res.x = movement_direction_normalized_x * (0.016 * 100 * speed);
	res.y = movement_direction_normalized_y * (0.016 * 100 * speed);
	return res;
}

//VECTOR ����ü�� ����Ͽ� ��Ȯ���� ����Ų �̵� �Լ� �Դϴ�
VECTOR MoveForwardVector(POINT target, POINT d, int speed)
{
	LONG x = target.x;
	LONG y = target.y;

	VECTOR res;
	VECTOR direction;
	direction.x = (d.x - x);
	direction.y = (d.y - y);

	double length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	double movement_direction_normalized_x = (double)direction.x / length;
	double movement_direction_normalized_y = (double)direction.y / length;

	res.x = movement_direction_normalized_x * (0.016 * 100 * speed);
	res.y = movement_direction_normalized_y * (0.016 * 100 * speed);
	return res;
}

//�ݶ��̴��� �Բ� �̵��ϴ� �Լ� �Դϴ�
void TransformWithColider(GAME_OBJECT* obj, POINT v)
{
	POINT move;
	move = subtractPoint(v, obj->point);

	obj->point = v;

	obj->colider.end_x += move.x;
	obj->colider.end_y += move.y;
	obj->colider.start_x += move.x;
	obj->colider.start_y += move.y;
}

//Ư����ġ�� �̵��ϱ� ���� ù��° �̵� ���� ���մϴ�
POINT getFirstStep(POINT target, POINT destination, int speed)
{
	//speed += 50;
	POINT tmp;
	tmp.x = (destination.x - target.x)/ (100 - speed);
	tmp.y = (destination.y - target.y)/ (100 - speed);

	return tmp;
}

//Bresenham�˰����� Ȱ���Ͽ� Ư����ġ�� �Ϻ��ϰ� �̵��մϴ�
//������ �̵��ϴ� ����� ������ �ʾ� ������� �ʽ��ϴ�
POINT getFirstStepBresenham(BRESENHAM * data)
{
	POINT tmp;
	
	tmp.x = 2;
	tmp.y = 0;

	// �ߴ����� 0���� ������ �׿� �´� �������� �Ǻ��� ����, y���� �״��
	if (data->F < 0)
	{
		data->F += data->dF1;
	}
	else // �ߴ����� 0���� ũ�ų� ������ �׿� �´� �������� �Ǻ��� ����, y���� ����
	{
		tmp.y = 2;
		data->F += data->dF2;
	}

	return tmp;
}

//���� �������� �Ÿ��� ���ϴ� �Լ��Դϴ�
int getDistance(POINT a, POINT b) 
{
	POINT tmp;
	tmp.x = a.x - b.x;
	tmp.y = a.y - b.y;
	return sqrt(pow(tmp.x, 2) + pow(tmp.y, 2));
}