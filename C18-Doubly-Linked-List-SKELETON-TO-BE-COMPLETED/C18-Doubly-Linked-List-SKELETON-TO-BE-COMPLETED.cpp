// C18-Doubly-Linked-List-SKELETON-TO-BE-COMPLETED.cpp
// C18-Doubly-Linked-Lists-App.cpp 

#include "DList.h"

//Prototypes
void experiment01();
void experiment02();
void experiment03();
void experiment04();

//--------------------------------------------------
int main()
{
    //experiment01();   // Create sorted list using insertInOrder()
    //experiment02();   // Merge two sorted lists
    //experiment03();     // Remove from a list nodes included in another list
    experiment04();     // Remove from me nodes included in another list

}

//User-defined methods ------------------------------
void experiment04()
{
    DList<int> lst1;
    lst1.insertLast(44);
    lst1.insertLast(55);
    lst1.insertLast(22);
    cout << " List-1\n" << lst1.toString() << endl;

    DList<int> lst2;
    lst2.insertLast(44);
    lst2.insertLast(11);
    lst2.insertLast(66);
    lst2.insertLast(88);
    lst2.insertLast(33);
    lst2.insertLast(22);
    cout << " List-2\n" << lst2.toString() << endl;

    //remove from lst1 nodes present in lst2
    lst1.removeFromMeGivenNodes(lst2);
    cout << " Reduced List-1\n" << lst1.toString() << endl;

    cout << "\nAll done!\n";
}




void experiment03()
{
    DList<int> lst1;
    lst1.insertLast(44);

    lst1.insertLast(55);
    lst1.insertLast(22);

    cout << " List-1\n" << lst1.toString() << endl;

    DList<int> lst2;
    lst2.insertLast(44);
    lst2.insertLast(11);
    lst2.insertLast(66);
    lst2.insertLast(88);
    lst2.insertLast(33);
    cout << " List-2\n" << lst2.toString() << endl;

    //remove from lst1 nodes present in lst2
    DList<int> lst3;
    Node<int>* p1 = lst1.head;
    while (p1 != nullptr)
    {
        Node<int>* p2 = lst2.find(p1->data);
        if (p2 == nullptr)
        {
            lst3.insertLast(p1->data);
        }
        p1 = p1->next;
    }
    cout << " Reduced List-3\n" << lst3.toString() << endl;

}



void experiment02()
{
    DList<int> lstSorted1;
    lstSorted1.insertInOrder(44);

    lstSorted1.insertInOrder(55);
    lstSorted1.insertInOrder(22);

    cout << "Ordered List-1\n" << lstSorted1.toString() << endl;

    DList<int> lstSorted2;
    lstSorted2.insertInOrder(44);
    lstSorted2.insertInOrder(11);
    lstSorted2.insertInOrder(66);
    lstSorted2.insertInOrder(88);
    lstSorted2.insertInOrder(33);
    cout << "Ordered List-2\n" << lstSorted2.toString() << endl;


    //merge two sorted lists
    DList<int> lst3;
    Node<int>* p1 = lstSorted1.head;
    Node<int>* p2 = lstSorted2.head;

    while (p1 != nullptr && p2 != nullptr)
    {
        if ((p1->data) < (p2->data))
        {
            lst3.insertLast(p1->data);
            p1 = p1->next;
        }
        else
        {
            lst3.insertLast(p2->data);
            p2 = p2->next;
        }

    }

    while (p1 != nullptr)
    {
        lst3.insertLast(p1->data);
        p1 = p1->next;
    }

    while (p2 != nullptr)
    {
        lst3.insertLast(p2->data);
        p2 = p2->next;
    }


    cout << "Combined List\n" << lst3.toString() << endl;
}


void experiment01()
{
    DList<int> lstSorted;
    lstSorted.insertInOrder(44);
    lstSorted.insertInOrder(11);
    lstSorted.insertInOrder(55);
    lstSorted.insertInOrder(22);
    lstSorted.insertInOrder(44);
    lstSorted.insertInOrder(33);
    cout << "Ordered List\n" << lstSorted.toString() << endl;

    DList<int> lstUnSorted;
    lstUnSorted.insertLast(44);
    lstUnSorted.insertLast(11);
    lstUnSorted.insertLast(55);
    lstUnSorted.insertLast(22);
    lstUnSorted.insertLast(44);
    lstUnSorted.insertLast(33);
    cout << "Un-ordered List\n" << lstUnSorted.toString() << endl;

}