#include <stdio.h>
#include <stdlib.h>

/*
 * Structure that represents a graph data type.
 */
struct Friendship_Graph {
    int nAccounts;
    int** adjacencyMatrix; // adjacency matrix is just like a square matrix
};

/*
 * Initializes a graph with the specified number of accounts.
 * @param numAccounts The number of accounts in the graph
 * @return A pointer to the initialized graph
 */

struct Friendship_Graph* initializeGraph(int numAccounts) {
    struct Friendship_Graph* graph = (struct Friendship_Graph*)malloc(sizeof(struct Friendship_Graph));
    graph->nAccounts = numAccounts;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(numAccounts * sizeof(int*));
    for (int i = 0; i < numAccounts; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(numAccounts, sizeof(int));
    }

    return graph;
}

/*
 * Adds an edge between two nodes in the graph, representing a friendship.
 * @param graph The friendship graph
 * @param node1 The ID of the first person
 * @param node2 The ID of the second person
 */
void InsertEdge(struct Friendship_Graph* graph, int node1, int node2) 
{
    graph->adjacencyMatrix[node1][node2] = 1;
    graph->adjacencyMatrix[node2][node1] = 1; // friendship is bi=directional (goes both ways)
}

/*
 * Displays the friend list for a person with the specified ID.
 * @param graph The friendship graph
 * @param personId The ID of the person
 */
void ShowFriends(struct Friendship_Graph* graph, int personId) 
{
    if (personId < 0 || personId >= graph->nAccounts) {
        printf("Error: Person with ID %d not found in the dataset.\n", personId);
    } else {
        printf("Friend list for person with ID %d: ", personId);
        int totalFriends = 0;
        for (int i = 0; i < graph->nAccounts; ++i) {
            if (graph->adjacencyMatrix[personId][i] == 1) {
                printf("%d ", i);
                totalFriends++;
            }
        }
        printf("\nTotal number of friends: %d\n", totalFriends);
    }
}

/*
 * Checks if two people are connected in the friendship graph.
 * @param graph The friendship graph
 * @param person1 The ID of the first person
 * @param person2 The ID of the second person
 * @return 1 if there is a connection, 0 otherwise
 */

 // not sure if this is working properly 
int CheckConnections(struct Friendship_Graph* graph, int person1, int person2) {
    if (person1 < 0 || person1 >= graph->nAccounts || person2 < 0 || person2 >= graph->nAccounts) {
        printf("Error: One or both persons not found in the dataset.\n");
        return 0;
    }

    // check for a connection using depth-first search (DFS search)
    int* visited = (int*)calloc(graph->nAccounts, sizeof(int));
    int stack[graph->nAccounts];
    int top = -1; // initialize the top of the stack
    int current = person1;
    visited[current] = 1;

    printf("There is a connection from %d to %d!\n", person1, person2);
    printf("%d is friends with", person1);

    while (1) {
        int foundConnection = 0;

        for (int i = 0; i < graph->nAccounts; ++i) {
            if (graph->adjacencyMatrix[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;

                printf(" %d", i);

                if (i == person2) {
                    foundConnection = 1;
                    break;
                }
            }
        }

        if (foundConnection) {
            printf("\n");
            break;
        }

        if (top == -1) {
            printf("\n");
            printf("%d is not friends with %d.\n", person1, person2);
            break;
        }

        current = stack[top--];
        printf(" ->");
    }

    free(visited);
    return 1; // Connection found
}

/*
 * Frees the memory allocated for the friendship graph.
 * @param graph The friendship graph to be freed
 */
void purge(struct Friendship_Graph* graph) 
{
    for (int i = 0; i < graph->nAccounts; ++i) 
    {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

/*
 * Reads the network data from the file and initializes the friendship graph.
 * @param filePath The path to the file containing the network data
 * @return A pointer to the initialized friendship graph
 */
struct Friendship_Graph* FileReader(char* filePath) 
{
    FILE* file = fopen(filePath, "r");
    if (file == NULL) 
    {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of accounts and friendships from the first line
    int numAccounts, numFriendships;
    fscanf(file, "%d %d", &numAccounts, &numFriendships);

    // Initialize the graph
    struct Friendship_Graph* socialGraph = initializeGraph(numAccounts);

    // Read each line describing a friendship and add edges to the graph
    for (int i = 0; i < numFriendships; ++i) 
    {
        int person1, person2;
        fscanf(file, "%d %d", &person1, &person2);
        InsertEdge(socialGraph, person1, person2);
    }

    fclose(file);

    return socialGraph;
}

int main() 
{
    // initialize variables
    char filePath[20]; 
    int choice, personId, person1, person2;
    
    // Get the file path as input
    printf("Enter the file path: ");
    scanf("%s", filePath);

    // Read the network data and initialize the graph
    struct Friendship_Graph* socialGraph = FileReader(filePath);

    // display menu repeatedly until the user chooses to exit
    do {
        // display menu
        printf("\nMENU:\n");
        printf("1. Display Friend List\n");
        printf("2. Display Connections\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display Friend List
                printf("Enter the ID number of a person: ");
                scanf("%d", &personId);
                ShowFriends(socialGraph, personId);
                break;

            case 2:
                // Display Connections
                printf("Enter two ID numbers: ");
                scanf("%d %d", &person1, &person2);
                if (CheckConnections(socialGraph, person1, person2)) {
                    printf("Connection exists between %d and %d.\n", person1, person2);
                } else {
                    printf("Connection does not exist.\n");
                }
                break;

            case 3:
                // exit the program
                printf("Exiting the program.\n");
                break;

            default:
                // invalid choice
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }

    } while (choice != 3);

    // free the memory allocated for the graph
    purge(socialGraph);

    return 0;
}











