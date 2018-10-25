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

//Этот класс представляет собой направленный граф, используя представление списка смежности
class Graph
{
	int V; // номер узла
	list<int> *adj; // Указатель на массив, содержащий списки смежности
public:
	Graph(int V);
	void addEdge(int v, int w); // метод добавляет ребро
	void BFS(int s); // последовательный алгоритм
	void BFSparallelOpenMP(int s); // параллельный алгоритм
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // добавляем w в конец списка v
}

void Graph::BFS(int s)
{
	cout << "Начинаем поиск в ширину с  вершины ";
	cout << s << " : " << endl;
	cout << "Введите количество тестов: ";
	cin >> coltest;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Работа последовательного BFS" << endl;
	clock_t start_time = clock();
	for (int counter = 0; counter < coltest; counter++){
		int *visited = new int[V];  
		list<int> queue;
		queue.clear();
		// пометим все узлы как непосещенные
		for (int i = 0; i < V; i++)
			visited[i] = 0;
		//Отметить текущий узел как посещаемый и поставить его в конец очереди
		queue.push_back(s);
		visited[s] = 1;
		while (!queue.empty())
		{
			//Удаление вершины из очереди
			int u = queue.front();
			//cout << u << " ";
			queue.pop_front();
			// i Будет использоваться для получения всех смежных вершин вершины
			//Получить все смежные вершины нвершины s
			//Если соседний объект не был посещен, отметьте его посещенным и установите его в очередь
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
		cout << endl << "Время затраченное на поиск в ширину: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << endl;
		cout << "Количество ребер: " << edges << endl;
		start_time = clock();
		edges = 0;
	}
	cout << endl << "------------------------------------------------------------------------" << endl;
	cout << "Среднее арифметическое: " << sum / coltest << endl;
	cout << endl << "------------------------------------------------------------------------" << endl;
	//sum = 0;
}

void Graph::BFSparallelOpenMP(int s)
{
		cout << "Начинаем поиск в ширину с  вершины ";
		cout << s << " : " << endl;
		cout << "Введите количество тестов: ";
		cin >> coltest;
		//cout << "Введите количество потоков: ";
		//cin >> t;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Работа параллельного BFS" << endl;
		for (int counter = 0; counter < coltest; counter++){
			clock_t start_time = clock();
			int *visited = new int[V];
			list <int> Q;
			Q.clear();
			// пометим все узлы как непосещенные
			for (int i = 0; i < V; i++)
				visited[i] = 0;
			//Отметить текущий узел как посещаемый и поставить его в конец очереди
			Q.push_back(s);
			visited[s] = 1;
			// i Будет использоваться для получения всех смежных вершин вершины
			list<int>::iterator j;
			while (!Q.empty())
			{
				int u = Q.front();
				Q.pop_front();
				//cout << u << " ";
				int size = adj[u].size(); // количество смежных вершин 
				j = adj[u].begin(); // первый смежный узел
				int vv;
				#pragma omp parallel for 
				for (int k = 0; k < size; k++)
				{
					{
						vv = *j;
						++j;
					}
					//Если соседний объект не был посещен, отметьте его посещенным и установите его в очередь
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
			cout << endl << "Время затраченное на поиск в ширину: " << (float)(end_time - start_time) / CLOCKS_PER_SEC << endl;
			cout << "Количество ребер: " << edges << endl;
			edges = 0;
		}
		cout << endl << "------------------------------------------------------------------------" << endl;
		cout << "Среднее арифметическое: " << psum / coltest << endl;
		cout << endl << "------------------------------------------------------------------------" << endl;
		//sum = 0;
}
int main()
{
	setlocale(0, "RUS");
	int N;
	cout << "Введите количество узлов графа: ";
	cin >> N;
	Graph g(N);
	for (int i = 0, j = 1; j <= N; i++, j++){
		/* Добавляем ребра графу */
		g.addEdge(i, j);
		g.addEdge(i, j + 1);
	}
	g.BFS(0);
	g.BFSparallelOpenMP(0);
	cout << "Отношение Serial/Parallel: " << (sum / coltest) / (psum / coltest) << endl;
	return 0;
}