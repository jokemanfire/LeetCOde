#include"global.h"




int main()
{
	int n;
	cin >> n;
	getchar();
	vector<int> Type(n+1,0);
	vector<int> Nodes(n+1,0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		Type[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		Nodes[i] = temp;
	}
	int Count_Wgood = 0;
	int Count_Bgood = 0;

	vector<bool> WhiteNode(Nodes.size()+1,false);
	vector<bool> BlackNode(Nodes.size()+1,true);

	for (int i = 1; i < Nodes.size(); i++)
	{
		int j = 1;

		while (j < Nodes.size())
		{
			if (j == i)
			{
				j++;
				continue;
			}
			if (Nodes[j] == i && Type[i] == 0 && Type[j] == 1) //�������ڵ�Ϊi ��Ϊ��
			{
				WhiteNode[i] = true;
			}
			j++;
		}
		
	}
	for (int i = 1; i < Nodes.size(); i++)
	{
		int j = 1;

		while (j < Nodes.size())
		{
			if (j == i)
			{
				j++;
				continue;
			}
			if (Nodes[j] == i && Type[i] == 1 && Type[j] == 1) //�������ڵ�Ϊi ��Ϊ�� jΪ��
			{
				BlackNode[i] = false;
			}
			j++;
		}


	}



	for (int i = 1; i < Nodes.size(); i++)
	{
		int j = 1;
		int count = 0;
		while (j < Nodes.size())
		{
			if (Nodes[j] == i) //�������ڵ�Ϊi
				count++;
			j++;
		}
		if (Type[i] == 0)
		{
			if (count == 0 || WhiteNode[i]) //���ڸýڵ�Ϊ��ɫ�ڵ�
				Count_Wgood++;
		}
		else
		{
			if (count == 0 || BlackNode[j]) //���ڸýڵ�Ϊ��ɫ�ڵ�
				Count_Bgood++;
		}
	}
	cout << Count_Wgood << Count_Bgood;
}