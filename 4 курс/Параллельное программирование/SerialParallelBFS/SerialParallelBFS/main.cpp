#include <iostream>
#include <ctime>
#include <omp.h>
#include <list>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;
int t;
double sum = 0;
double psum = 0;
int coltest = 0;
int edges = 0;
double *result = new double[];
double *presult = new double[];

//���� ����� ������������ ����� ������������ ����, ��������� ������������� ������ ���������
class Graph
{
	int V; // ����� ����
	list<int> *adj; // ��������� �� ������, ���������� ������ ���������
public:
	Graph(int V);
	void addEdge(int v, int w); // ����� ��������� �����
	void BFS(int s); // ���������������� ��������
	void BFSparallelOpenMP(int s); // ������������ ��������
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // ��������� w � ����� ������ v
}

void Graph::BFS(int s)
{
	cout << "�������� ����� � ������ �  ������� ";
	cout << s << " : " << endl;
	cout << "������� ���������� ������: ";
	cin >> coltest;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "������ ����������������� BFS" << endl;
	clock_t start_time = clock();
	for (int counter = 0; counter < coltest; counter++){
		int *visited = new int[V];  
		list<int> queue;
		queue.clear();
		// ������� ��� ���� ��� ������������
		for (int i = 0; i < V; i++)
			visited[i] = 0;
		//�������� ������� ���� ��� ���������� � ��������� ��� � ����� �������
		queue.push_back(s);
		visited[s] = 1;
		while (!queue.empty())
		{
			//�������� ������� �� �������
			int u = queue.front();
			//cout << u << " ";
			queue.pop_front();
			// i ����� �������������� ��� ��������� ���� ������� ������ �������
			//�������� ��� ������� ������� �������� s
			//���� �������� ������ �� ��� �������, �������� ��� ���������� � ���������� ��� � �������
			for (list<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++)
			{
				int vv = *i;
				if (visited[vv] == 0)
				{
					visited[vv] = 1;
					queue.push_back(vv);
					if (vv > 0)
					{
						edges = edges + 1;
					}
				}

			}
		}
		delete[] visited;
		clock_t end_time = clock();
		cout << endl;
		result[counter] = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		sum += result[counter];
		cout << endl << "����� ����������� �� ����� � ������: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
		cout << "���������� �����: " << edges << endl;
		start_time = clock();
		edges = 0;
	}
	cout << endl << "------------------------------------------------------------------------" << endl;
	cout << "������� ��������������: " << sum / coltest << endl;
	cout << endl << "------------------------------------------------------------------------" << endl;
	//sum = 0;
}

void Graph::BFSparallelOpenMP(int s)
{
		cout << "�������� ����� � ������ �  ������� ";
		cout << s << " : " << endl;
		cout << "������� ���������� ������: ";
		cin >> coltest;
		//cout << "������� ���������� �������: ";
		//cin >> t;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "������ ������������� BFS" << endl;
		for (int counter = 0; counter < coltest; counter++){
			clock_t start_time = clock();
			int *visited = new int[V];
			list <int> Q;
			Q.clear();
			// ������� ��� ���� ��� ������������
			for (int i = 0; i < V; i++)
				visited[i] = 0;
			//�������� ������� ���� ��� ���������� � ��������� ��� � ����� �������
			Q.push_back(s);
			visited[s] = 1;
			// i ����� �������������� ��� ��������� ���� ������� ������ �������
			list<int>::iterator j;
			while (!Q.empty())
			{
				int u = Q.front();
				Q.pop_front();
				//cout << u << " ";
				int size = adj[u].size(); // ���������� ������� ������ 
				j = adj[u].begin(); // ������ ������� ����
				int vv;
				#pragma omp parallel for 
				for (int k = 0; k < size; k++)
				{
					{
						vv = *j;
						++j;
					}
					//���� �������� ������ �� ��� �������, �������� ��� ���������� � ���������� ��� � �������
					if (visited[vv] == 0)
					{
						visited[vv] = 1;
						Q.push_back(vv);
						if (vv > 0)
						{
							edges = edges + 1;
						}
					}
				}
			}
			delete[] visited;
			clock_t end_time = clock();
			presult[counter] = (double)(end_time - start_time) / CLOCKS_PER_SEC;
			psum += presult[counter];
			cout << endl;
			cout << endl << "����� ����������� �� ����� � ������: " << (float)(end_time - start_time) / CLOCKS_PER_SEC << endl;
			cout << "���������� �����: " << edges << endl;
			edges = 0;
		}
		cout << endl << "------------------------------------------------------------------------" << endl;
		cout << "������� ��������������: " << psum / coltest << endl;
		cout << endl << "------------------------------------------------------------------------" << endl;
		//sum = 0;
}
int main()
{
	setlocale(0, "RUS");
	int N;
	cout << "������� ���������� ����� �����: ";
	cin >> N;
	Graph g(N);
	for (int i = 0, j = 1; j <= N; i++, j++){
		/* ��������� ����� ����� */
		g.addEdge(i, j);
		g.addEdge(i, j + 1);
	}
	g.BFS(0);
	g.BFSparallelOpenMP(0);
	cout << "��������� Serial/Parallel: " << (sum / coltest) / (psum / coltest) << endl;
	return 0;
}