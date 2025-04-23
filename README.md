# CCDSALG S13 Group 7 Projects

## Major Course Output 1: Sorting Algorithms

### Introduction
This project compares and contrasts different sorting algorithms, focusing on their execution times and use cases. The implemented algorithms include:
- **Insertion Sort**
- **Selection Sort**
- **Merge Sort**
- **Comb Sort**

Each algorithm was benchmarked to determine average runtime, and empirical frequency counts were analyzed. The results were compared to derive insights into their performance across various datasets.

### Data Structures and Algorithms
- **Insertion Sort**: An in-place, stable algorithm that builds the sorted array incrementally.
- **Selection Sort**: An in-place, unstable algorithm that repeatedly selects the smallest element from the unsorted portion.
- **Merge Sort**: An out-of-place, stable algorithm using a divide-and-conquer approach.
- **Comb Sort**: An in-place, unstable algorithm that improves Bubble Sort by using a shrinking gap.

### Key Findings
1. **Small Datasets (10-500 lines)**: All algorithms performed similarly due to negligible time complexity differences.
2. **Medium Datasets (25,000 lines)**: Merge Sort and Comb Sort outperformed Insertion and Selection Sort.
3. **Large Datasets (100,000 lines)**: Merge Sort was the most efficient, while Insertion and Selection Sort became impractical due to their quadratic time complexity.

### Challenges
- Memory allocation issues in C for large datasets.
- Ensuring accurate benchmarking by resetting arrays between iterations.

### Members and Contributions
| Member                     | Contributions                                                                 |
|----------------------------|-------------------------------------------------------------------------------|
| Clavano, Angelica Therese  | Comb Sort implementation, debugging, empirical counts, execution time analysis. |
| Homssi, Yazan M.           | Selection Sort implementation, comparative analysis, summary of findings.      |
| Young, Henzley Emmanuel S. | Insertion Sort implementation, report introduction, debugging.                |
| Jimenez, Yves Alvin Andrei | Merge Sort implementation, execution time analysis, summary of findings.      |

---

## Major Course Output 2: Social Graph Dataset

### Introduction
This project processes a Facebook snapshot dataset (2005) to analyze social networks. The program converts graph data into an adjacency matrix and provides functionalities:
1. Display a user's friend list.
2. Check connections between two users.
3. Exit the program.

### Data Structures and Algorithms
- **Adjacency Matrix**: Represents the social graph, where `1` indicates a connection and `0` otherwise. This structure was chosen for its simplicity and efficiency in checking bidirectional relationships.
- **Depth-First Search (DFS)**: Used to traverse the graph and check connections between users. DFS was selected due to its familiarity and ease of implementation with stacks.

### Key Features
1. **Friend List Display**: Iterates through the adjacency matrix to list all friends of a given user.
2. **Connection Check**: Uses DFS to determine if a path exists between two users.

### Challenges
- Handling large datasets efficiently in C.
- Ensuring correct memory allocation and deallocation for the adjacency matrix.

### Members and Contributions
| Member                     | Contributions                                                                 |
|----------------------------|-------------------------------------------------------------------------------|
| Clavano, Angelica Therese  | Data structure implementation, adjacency matrix setup, debugging.             |
| Homssi, Yazan M.           | Algorithm selection (DFS), traversal logic, report sections.                  |
| Young, Henzley Emmanuel S. | Code testing, dataset validation, execution time analysis.                    |
| Jimenez, Yves Alvin Andrei | Core functionality implementation, summary of findings.                       |

### References
- Depth-First Search: [Programiz](https://www.programiz.com/dsa/graph-dfs)
- Adjacency Matrix: [Programiz](https://www.programiz.com/dsa/graph-adjacency-matrix)
- Sorting Algorithms: [GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)

---

## Summary
These projects provided hands-on experience with sorting algorithms and graph traversals, highlighting the importance of selecting appropriate data structures and algorithms based on problem constraints. The group gained insights into memory management, algorithm efficiency, and collaborative coding practices.