#pragma once
#include"stdafx.h"
 
//using namespace std;
struct XET
{
	float xmin, ymax, ymin, dx;
}pNET[1024];
//N�����������  
struct node
{
	float x, y;
}point[1024];
//��ͼ  
inline void drawColor(float a, float b, int y)
{
	int x;
	for (x = a + 0.5; x <= b + 0.5; x++)
		putpixel(x, y, RED);
	//���԰��������ȡ��ע�ͣ����س������߹��̡�  
	//  system("pause");  
}
//���ȶ��б���ĳ��ɨ�����ϵ�xֵ  
priority_queue<float, vector<float>, greater<float> >s;

inline void ScanConversionTest()
{
	//i,jΪforѭ���õ��ģ�tΪpNET[]������±�  
	int i, j, t = 0, N;
	//min_yΪ���ж���y�������Сֵ��max_yΪ���ж���y��������ֵ  
	int min_y = 0x3fffffff, max_y = -1;
	printf("�����붥����N=:");
	scanf("%d", &N);
	printf("�밴��ʱ������N����������꣨�ÿո�ֿ���\n");
	for (i = 0; i<N; i++)
	{
		scanf("%f %f", &point[i].x, &point[i].y);
		//�������ж���y�������ֵ  
		if (point[i].y>max_y)
			max_y = point[i].y;
		if (point[i].y<min_y)
			min_y = point[i].y;
	}
	for (i = min_y; i <= max_y; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (point[j].y == i)
			{
				//����ʱ�룬ĳ�����ǰһ������  
				if (point[(j - 1 + N) % N].y>point[j].y)
				{
					struct XET p;
					p.xmin = point[j].x;
					p.ymax = point[(j - 1 + N) % N].y;
					p.ymin = point[j].y;
					p.dx = (point[(j - 1 + N) % N].x - point[j].x) / (point[(j - 1 + N) % N].y - point[j].y);
					//�ж��Ƿ�Ϊ�ֲ���ֵ  
					if (point[(j + 1 + N) % N].y <= point[j].y)
						p.ymin++;
					pNET[t++] = p;
				}
				//����ʱ�룬ĳ����ĺ�һ������  
				if (point[(j + 1 + N) % N].y>point[j].y)
				{
					struct XET p;
					p.xmin = point[j].x;
					p.ymax = point[(j + 1 + N) % N].y;
					p.ymin = point[j].y;
					p.dx = (point[(j + 1 + N) % N].x - point[j].x) / (point[(j + 1 + N) % N].y - point[j].y);
					//�ж��Ƿ�Ϊ�ֲ���ֵ  
					if (point[(j - 1 + N) % N].y <= point[j].y)
						p.ymin++;
					pNET[t++] = p;
				}
			}
		}
	}
	initgraph(480, 480);
	//����ɨ���߽���ɨ��  
	for (i = min_y; i <= max_y; i++)
	{
		for (j = 0; j<t; j++)
		{
			//��ǰɨ������ĳ����֮��  
			if (pNET[j].ymin <= i&&pNET[j].ymax >= i)
			{
				s.push(pNET[j].xmin);
				//����xmin����  
				pNET[j].xmin += pNET[j].dx;
			}
		}
		while (!s.empty())
		{   //ÿ����һ��,a,b��Ϊɨ�����ϵ�x����  
			float a = s.top(); s.pop();
			float b = s.top(); s.pop();
			drawColor(a, b, i);
		}
	}
	getch();
	closegraph();
}