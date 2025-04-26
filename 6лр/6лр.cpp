#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Структура матрицы смежности
struct AMatrix {
    vector<vector<int>> matrix;

    AMatrix(int n) {
        matrix.resize(n, vector<int>(n, 0));
    }

    void addEdge(int from, int to) {
        matrix[from][to] = 1;
    }

    void print() {
        cout << "matrica smejnosty:\n";
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
};

// Структура списка смежности
struct AList {
    vector<vector<int>> list;

    AList(int n) {
        list.resize(n);
    }

    void addEdge(int from, int to) {
        list[from].push_back(to);
    }

    void print() {
        cout << "spisok smejnosty:\n";
        for (int i = 0; i < list.size(); i++) {
            cout << i << ": ";
            for (int to : list[i]) {
                cout << to << " ";
            }
            cout << "\n";
        }
    }
};

// Преобразование матрицы в список
AList matrixToList(const AMatrix& matrix) {
    int n = matrix.matrix.size();
    AList adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix.matrix[i][j] == 1) {
                adjList.addEdge(i, j);
            }
        }
    }
    return adjList;
}

// Преобразование списка в матрицу
AMatrix listToMatrix(const AList& adjList) {
    int n = adjList.list.size();
    AMatrix matrix(n);

    for (int i = 0; i < n; i++) {
        for (int to : adjList.list[i]) {
            matrix.addEdge(i, to);
        }
    }
    return matrix;
}

// Обход в ширину BFS
void BFS(const AList& adjList, int start) {
    int n = adjList.list.size();
    vector<bool> visited(n, false);
    queue<int> q;

    cout << "obhod v shiriny nachinaya s vershini " << start << ": ";

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int to : adjList.list[v]) {
            if (!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }
    cout << "\n";
}

//задание 4--------------------------------------------------------------------------------------
// Вспомогательная рекурсивная функция для DFS
void DFSUtil(const AList& adjList, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int to : adjList.list[v]) {
        if (!visited[to]) {
            DFSUtil(adjList, to, visited);
        }
    }
}

// Обход в глубину DFS
void DFS(const AList& adjList, int start) {
    int n = adjList.list.size();
    vector<bool> visited(n, false);

    cout << "obhod v glybiny nachinaya s vershini " << start << ": ";
    DFSUtil(adjList, start, visited);
    cout << "\n";
}

//задание 5-------------------------------------------------------------------------------------------------------------------
// Вспомогательная рекурсивная функция для топологической сортировки
void topologicalSortUtil(const AList& adjList, int v, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    for (int to : adjList.list[v]) {
        if (!visited[to]) {
            topologicalSortUtil(adjList, to, visited, Stack);
        }
    }
    // После обработки всех соседей — добавить вершину в стек
    Stack.push(v);
}

// Функция топологической сортировки
void topologicalSort(const AList& adjList) {
    int n = adjList.list.size();
    vector<bool> visited(n, false);
    stack<int> Stack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(adjList, i, visited, Stack);
        }
    }

    cout << "topologicheskaya sortirovka grafa: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << "\n";
}

int main() {
    // Создание графа с 7 вершинами (0...6)
    AMatrix graph(7);

    // Добавляем рёбра по твоему описанию
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(3, 1);
    graph.addEdge(1, 4);
    graph.addEdge(3, 2);
    graph.addEdge(3, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 2);
    graph.addEdge(6, 5);

    // Печать матрицы
    graph.print();

    // Преобразование в список смежности
    AList adjList = matrixToList(graph);
    adjList.print();

    // Преобразование обратно в матрицу и печать
    AMatrix graph2 = listToMatrix(adjList);
    graph2.print();

    // BFS обход
    BFS(adjList, 0);

    //задание 4
    // DFS обход
    DFS(adjList, 0);

    //задание5
    // Топологическая сортировка
    topologicalSort(adjList);

    return 0;
}
