// // BFS and DFS traversals using Adjacency list

// #include <iostream>
// using namespace std;

// class node
// {
//     int data;
//     node *next;

// public:
//     friend class graph;
//     node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

// class graph
// {
//     node *G[20];
//     int visited[20];

// public:
//     graph(int n)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             G[i] = new node(i);
//         }
//     }

//     void create(int n)
//     {
//         node *temp, *q;
//         int s, d;
//         cout << "Enter source and destination for each edge : " << endl;
//         for (int i = 0; i < n; i++)
//         {
//             cout << "Edge " << i << " : ";
//             cin >> s >> d;
//             temp = G[s];
//             while (temp->next != NULL)
//                 temp = temp->next;
//             q = new node(d);
//             temp->next = q;
//             temp = G[d];
//             while (temp->next != NULL)
//                 temp = temp->next;
//             q = new node(s);
//             temp->next = q;
//         }
//     }

//     void BFS(int v1)
//     {
//         node *temp;
//         int Q[20], f = 0, r = -1;
//         for (int i = 0; i < 20; i++)
//         {
//             Q[i] = -1;
//             visited[i] = 0;
//         }
//         Q[++r] = v1;
//         visited[v1] = 1;
//         while (Q[f] != -1)
//         {
//             int x = Q[f];
//             cout << x << " ";
//             temp = G[x];
//             while (temp != NULL)
//             {
//                 if (visited[temp->data] == 0)
//                 {
//                     Q[++r] = temp->data;
//                     visited[temp->data] = 1;
//                 }
//                 temp = temp->next;
//             }
//             f++;
//         }
//     }

//     void DFS(int v1)
//     {
//         for (int i = 0; i < 20; i++)
//             visited[i] = 0;
//         dfs(v1, visited);
//     }

//     void dfs(int v, int visited[])
//     {
//         cout << v << " ";
//         visited[v] = 1;
//         node *temp = G[v];
//         while (true)
//         {
//             while (temp != NULL && visited[temp->data] != 0)
//                 temp = temp->next;
//             if (temp != NULL)
//                 dfs(temp->data, visited);
//             else
//                 break;
//         }
//     }

//     void search()
//     {
//         while (true)
//         {
//             int n;
//             cout << "\nEnter the vertex to be searched : (enter -1 to exit) : ";
//             cin >> n;
//             if (n < 0)
//                 break;
//             else if (visited[n] == 1)
//                 cout << "Vertex found";
//             else
//                 cout << "Vertex not found";
//         }
//     }
// };

// int main()
// {
//     int n;
//     cout << "Enter number of vertices in the graph : ";
//     cin >> n;
//     graph g(n);

//     cout << "Enter number of edges in your graph : ";
//     cin >> n;
//     g.create(n);

//     cout << "Enter the vertex for initiating BFS : ";
//     cin >> n;
//     g.BFS(n);

//     cout << "\nEnter the vertex for initiating DFS : ";
//     cin >> n;
//     g.DFS(n);

//     g.search();
// }

// /*				0
//                / \
//               1   2
//              / \   \
//             3  4    5
//             \ /      \
//              6        7
// */
// /*
//             0
//           / | \
//          /  |  \
//         1   4   3
//          \  |  /
//           \ | /
//             2
//  */

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int v;   // no of vertices
    int **p; // matrix representation
public:
    Graph()
    {
        v = 0;
        p = NULL;
    }

    Graph(int n)
    {
        v = n;
        p = new int *[v];
        for (int i = 0; i < v; i++) // initialising the matrix
        {
            p[i] = new int[v];
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                p[i][j] = 0;
                p[j][i] = 0;
            }
        }
    }

    void setGraph() // setting the graph
    {
        char x;
        for (int i = 0; i < v; i++)
        {
            for (int j = i; j < v; j++)
            {
                cout << "Are vertices " << i << " " << j << " connected(y/n)?";
                cin >> x;
                if (x == 'Y' || x == 'y')
                {
                    p[i][j] = 1;
                    p[j][i] = 1;
                }
            }
        }
    }

    void printGraph() // printing the graph
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS() // Breadth First Search
    {
        bool vis[v];
        for (int i = 0; i < v; i++)
            vis[i] = false;
        int vertex;
        cout << "Enter the start vertex: ";
        cin >> vertex;
        cout << "\n";
        queue<int> q;

        q.push(vertex);
        while (!q.empty())
        {
            vertex = q.front();
            cout << vertex << " ";
            vis[vertex] = true;
            q.pop();
            for (int i = 0; i < v; i++)
            {
                if (p[vertex][i] == 1 && !vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }

    void DFS() // Depth First Search
    {
        int vertex;
        cout << "Enter the vertex to start DFS: ";
        cin >> vertex;
        bool vis[v];
        for (int i = 0; i < v; i++)
            vis[i] = false;
        stack<int> st;
        st.push(vertex);
        while (!st.empty())
        {
            vertex = st.top();
            cout << vertex << " ";
            st.pop();
            vis[vertex] = true;
            for (int i = 0; i < v; i++)
            {
                if (p[vertex][i] == 1 && !vis[i])
                {
                    st.push(i);
                    vis[i] = true;
                }
            }
        }
    }

    void searchVertex()
    {
        int vertex = 0, ver;
        cout << "Enter the vertex to be searched: ";
        cin >> ver;
        bool vis[v];
        for (int i = 0; i < v; i++)
            vis[i] = false;

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                vertex = i;
                stack<int> st;
                st.push(vertex);
                while (!st.empty())
                {
                    vertex = st.top();
                    st.pop();
                    if (ver == vertex)
                    {
                        cout << "\nVertex " << ver << " is present in the graph\n";
                        return;
                    }
                    vis[vertex] = true;
                    for (int i = 0; i < v; i++)
                    {
                        if (p[vertex][i] == 1 && !vis[i])
                        {
                            st.push(i);
                            vis[i] = true;
                        }
                    }
                }
            }
        }
        cout << "\nVertex " << ver << " is not present in the graph\n";
    }
};

int main()
{
    bool cont = true;
    bool isEmpty = true;
    Graph g = Graph(1);
    int choice;
    while (cont)
    {
        cout << "\nEnter your choice: ";
        cout << "\n1. Set new graph";
        cout << "\n2. Print the graph";
        cout << "\n3. Print BFS from a vertex";
        cout << "\n4. Print DFS from a vertex";
        cout << "\n5. Search for a vertex";
        cout << "\n6. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int v;
            cout << "\nEnter the number of vertices: ";
            cin >> v;
            g = Graph(v);
            g.setGraph();
            isEmpty = false;
            break;
        case 2:
            if (!isEmpty)
            {
                cout << "\n\n";
                g.printGraph();
                cout << "\n\n";
            }
            else
                cout << "\nPlease Set the graph first\n";
            break;
        case 3:
            if (!isEmpty)
            {
                cout << "BFS is ";
                g.BFS();
                cout << "\n\n";
            }
            else
                cout << "\nPlease Set the graph first\n";
            break;
        case 4:
            if (!isEmpty)
            {
                cout << "DFS is ";
                g.DFS();
                cout << "\n\n";
            }
            else
                cout << "\nPlease Set the graph first\n";
            break;
        case 5:
            if (!isEmpty)
            {
                g.searchVertex();
            }
            else
                cout << "\nPlease Set the graph first\n";
            break;
        case 6:
            cont = false;
            break;
        }
    }
    return 0;
}