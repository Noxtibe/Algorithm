#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Bubble Sorting
// 
// Fonction pour trier un tableau d'entiers en utilisant le tri � bulles
/*
void bubbleSort(int array[], int n) 
{
    bool swapped; // Variable pour v�rifier si un �change a eu lieu dans une passe

    // Boucle externe pour parcourir le tableau n-1 fois
    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false; // Initialise swapped � false au d�but de chaque passe

        // Boucle interne pour comparer les �l�ments adjacents et les �changer si n�cessaire
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                // �changez les �l�ments array[j] et array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true; // D�finir swapped � true si un �change a eu lieu
            }
        }

        // Si aucun �change n'a eu lieu dans une passe, le tableau est tri�, sortez de la boucle
        if (!swapped) 
        {
            break;
        }
    }
}

int main() 
{
    int array[] = {100, 55, 25, 47, 22, 11, 90, 72, 33, 86};
    int n = sizeof(array) / sizeof(array[0]);

    std::cout << "Tableau non trie : ";
    for (int i = 0; i < n; i++) 
    {
        std::cout << array[i] << " ";
    }

    bubbleSort(array, n); // Appeler la fonction du tri � bulles

    std::cout << "\nTableau trie : ";
    for (int i = 0; i < n; i++) 
    {
        std::cout << array[i] << " ";
    }

    return 0;
}
*/


// Merge Sorting
//
// Fonction pour fusionner deux sous-tableaux tri�s en un seul tableau tri�
void merge(vector<int>& array, int left, int middle, int right) 
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Cr�ez des tableaux temporaires pour stocker les donn�es des deux moiti�s
    vector<int> leftSubarray(n1);
    vector<int> rightSubarray(n2);

    // Copiez les donn�es dans les tableaux temporaires leftSubarray[] et rightSubarray[]
    for (int i = 0; i < n1; i++) 
    {
        leftSubarray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) 
    {
        rightSubarray[i] = array[middle + 1 + i];
    }

    // Fusionnez les tableaux temporaires dans le tableau d'origine array[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (leftSubarray[i] <= rightSubarray[j]) 
        {
            array[k] = leftSubarray[i];
            i++;
        }
        else 
        {
            array[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    // Copiez les �l�ments restants de leftSubarray[], le cas �ch�ant
    while (i < n1) 
    {
        array[k] = leftSubarray[i];
        i++;
        k++;
    }

    // Copiez les �l�ments restants de rightSubarray[], le cas �ch�ant
    while (j < n2) 
    {
        array[k] = rightSubarray[j];
        j++;
        k++;
    }
}

// Fonction r�cursive pour trier un tableau en utilisant le tri fusion
void mergeSort(vector<int>& array, int left, int right) 
{
    if (left < right) 
    {
        // Trouvez le milieu du tableau
        int middle = left + (right - left) / 2;

        // Trier la premi�re moiti�
        mergeSort(array, left, middle);

        // Trier la deuxi�me moiti�
        mergeSort(array, middle + 1, right);

        // Fusionnez les deux moiti�s tri�es
        merge(array, left, middle, right);
    }
}



/*int main()
{
    vector<int> array = {100, 55, 25, 47, 22, 11, 90, 72, 33, 86};
    int n = array.size();

    cout << "Tableau non trie : ";
    for (int i = 0; i < n; i++) 
    {
        cout << array[i] << " ";
    }

    mergeSort(array, 0, n - 1); // Appeler la fonction de tri fusion

    cout << "\nTableau trie : ";
    for (int i = 0; i < n; i++) 
    {
        cout << array[i] << " ";
    }

    return 0;
}*/
