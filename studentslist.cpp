#include<iostream>
#include<string>


using namespace std;

// i will create a doubly linked list for my student instances and my students will be stored in the nodes of this linked list 
// since its a doubly linked list the nodes point both forwards (to the next node) and backwards (to the previous node)

// i will then create a structure for my node properties and pointers (next and previous pointers)
struct Node{
    // we add our student properties that will be stored in the node of the linked list 
    string name;
    int age;

    // we add pointers to the student Node that point forwards and backwards
    Node *next; // this pointer points to the next node (forwards);
    Node *prev; // this pointer points to the previous node (backwards);
};

// we create a function that creates our linked list of student nodes
void createList(Node *&first){
    // in our function we will just reference the first node but not copy or recreate it because we are making changes to it 
    // referencing pointers allows us to pass in pointers created in the main function as arguments to our function and make changes to them.
    // we create our new node
    Node *newNode = new Node;

    // we add data to our new node that we just created 
    string Name; 
    cout << "What is the name of the student you want to add: ";
    cin >> Name; // user enters the name

    int Age;
    cout << "What is the age of the student you want to add: ";
    cin >> Age; // user enters the age 

    // now we add the data to our new node that we created 
    newNode->name = Name; // the name the user input becomes the name of our newNode
    newNode->age = Age; // same with the age 

    // we create the links to our new node that we created with the existing nodes in the linked list 
    // we first check if the list is empty 
    if(first == nullptr){
        // if the referenced pointer is null then the list is empty 
        // this means our new node will automatically become the first node of our linked list
        newNode->next = nullptr;
        newNode->prev = nullptr;
        first = newNode; // the new node becomes our head node so the pointer that points to the head node then points to it 
    }else{
        // this means the list is not empty
        // we need to iterate until we reach the end of the list and add our new node to the end of the list 
        Node *current = first; // this is our node iterator.
        while(current != nullptr){
            if(current->next == nullptr){
                // if the next of the current node is null then we have reached the end of our linked list and we can add our new node
                current->next = newNode;
                newNode->next = nullptr;
                newNode->prev = current;
                break;
            }
            // we update our current node while iterating 
            current = current->next;
        }
    }
};

// we create a function that prints our linked list
void print(Node *&first){
   // again we reference our pointers not copy them 
   // we need to iterate our linked list 
   Node *current = first; // iterating node; we begin from the first node 
   while(current != nullptr){
     cout << "NAME: " << current->name << " AGE: " << current->age << "   ---->   ";

     // we always update our iterating node to the next node while iterating 
     current = current->next;
   }
   cout << "NULLPTR"; // after we reach the end;
}

// remove an element by name from the linked list. 
void removeByName(Node *&first){

    // getting the data of what the user wants to remove 
    string Name; 
    cout << "What student do you want to remove from the list: ";
    cin >> Name; // user enters their name 

    // we first check is the first node is the one with the student 
    if(first != nullptr){
        if(first->name == Name){
            // this means the node with the student we want to remove is the first node 
            // so we have to remove the first node
            // we store the address of the first pointer in a temporary pointer 
            Node *temp = first; // store our first pointer in a temporary pointer 
            first = first->next; // make our first pointer to point to the next node in the link, hence it becomes the head node

            if(first != nullptr){
                // we check and see if our next node in the sequence is not empty
                first->prev = nullptr; // since now it has the first pointer pointing to it so its previous has to point to nullptr since its the head 
            }
            // after we delete our previous node pointer 
            delete temp;
        }else{
            bool found = false; // tracks if we found the name 
            // we iterate the list to find the node with that student 
            Node *current = first; // iterating node
            Node *before = nullptr; // keeps track of the node before our current node.
            while(current != nullptr){
                // we iterate until the end.
                if(current->name == Name){
                    found = true;
                    // so it means we reached the node that we want to delete
                    before->next = current->next; 

                    // we check if we are trying to remove the last node 
                    if(current->next != nullptr){
                        current->next->prev = before; // this occurs if the node we are removing has another node infront of it 
                    }
                    delete current; // we delete the current node after breaking all its links 
                    break;
                }
                // updates
                before = current;
                current = current->next;
            }
            if(found == false){
                cout << "Cant find the student." <<endl;
            }
        }
    }else{
        cout << "List is empty." << endl;
    }
};

// create a function that searches for adult students 
void searchAges(Node *&first){
    // we again reference our first node
    int Age; // the age the user wants to search 
    cout << "What minimum age do you want to search for: ";
    cin >> Age;
    // we iterate the linked list checking the ages of our students at the nodes and only displaying the adults
    Node *current = first; // iterator node
    while(current != nullptr){
        //until the end
        if(current->age >= Age){
            // we check if the student at the current node has an age above or equal to the minimum age the user passed in 
            cout << "NAME: " << current->name << "  AGE:  " << current->age << "  ---->  "; // we output that student details.
        }

        // update our current node 
        current = current->next;
    }
}

// create a function that returns the minimum age of all the students
void minimumAge(Node *&first){
    // we reference our first node  
    if(first != nullptr){
        // then we have to create a variable to store our minimum number 
        // iterate through the linked list and update the minimum 
        int min = first->age; // we initialise the minimum as our first node age
        Node *current = first;// this is our iterating node
        while(current != nullptr){
            if(current->age <= min){
                // we check if the current node's age is less than minimum 
                min = current->age;

                // after updating our minimum we update our current node 
                current = current->next;
            }else{
                // we just update to the next node 
                current = current->next;
            }
        }
        // we output the minimum age
        cout << "The minimum age is: "<< min << endl;
    }else{
        cout << "The List is empty" << endl;
    }
};

// create a function that gets the sum of our ages 
void sumAges(Node *&first){
    // we iterate the link 
    // we check if the link is not empty
    if(first != nullptr){
        // we create our variable to store our sum 
        int sum = 0;
        Node *current = first; // iterating node 
        while(current != nullptr){
            // update the sum by adding it to the age of the current node
            sum = sum + current->age; 
            // update to the next node 
            current =  current->next;
        }
        cout << "The of all the ages is: " << sum << " years." << endl;
    }else{
        cout << "The list is empty." << endl;
    }
};

// function for finding the average of the ages 
void average(Node *&first){
    // we check if the list is empty 
    if(first != nullptr){
        // we iterate the link and get the sum and also get the number of elements in the linked list 
        // we create our variable to store our sum 
        double sum = 0;
        // we create a variable to store the count of the elements in our linked list 
        double count = 0;
        Node *current = first; // iterating node 
        while(current != nullptr){
            // update the sum by adding it to the age of the current node
            sum = sum + current->age; 
            // update our count variable 
            count++;
            // update to the next node 
            current =  current->next;
        }
        // we solve our average of ages 
        double average = (sum/count);
        cout << "The average of the ages is: " << average << endl;
    }else{
        cout << "The list is empty." << endl;
    }
}


int main(){

    // we need to create the pointer that we reference in our functions 
    Node *first = nullptr; // initiated to a nullptr since the list is empty 

    // we create our nodes referencing the first pointer that we created in our main function
    createList(first);
    createList(first);
    createList(first);
    createList(first);
    print(first);

    cout << endl;
    // removing element by name 
    removeByName(first);
    print(first);

    cout << endl;
    // we search the list and display our students with the age greater than the age the user inputs
    searchAges(first);

    // we find the minimum age 
    cout << endl;
    minimumAge(first);

    // we find the sum of the ages of the students in the linked list
    cout << endl;
    sumAges(first);

    // we find the average of our ages of the students in the linked list 
    cout << endl;
    average(first);

    return 0;
}