//Stack implementation all stach operations.
//Menu to enter operation
//1.  isEmpty()
//2.  isFull()
//3.  Push()
//4.  pop()
//5.  peak()
//6.  count()
//7.  update()
//8.  display() 
//9.  Search ()
//10. Update_any_position ()
//11. Insert_any_position ()
//12. Delete_from_beginning ()
//13. Delete_from_end()
//14. Delete_any_position ()

#include<iostream>
#include<string>

using namespace std;

class Stack {
private:
  int top;
  int arr[5];

public:
  // Using Constructor here
  Stack() {
    top = -1; // For the very First time stack is empty
    for (int i = 0; i < 5; i++) {
      arr[i] = 0;
    }
  }

  //  isEmpty function
  bool isEmpty() {
    return top == -1;
  }

  //  isFull function
  bool isFull() {
    return top == 4; // Because array size is 5
  }

  // Push operation function
  void push(int val) {
    if (isFull()) {
      cout << "Stack overflow" << endl;
    } else {
      top++;
      arr[top] = val;
    }
  }

  // Pop operation function
  int pop() {
    if (isEmpty()) {
      cout << "Stack underflow" << endl;
      return 0;
    } else {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }

  // Count the total  values in the stack
  int count() {
    return (top + 1);
  }

  //  Peek operation
  int peek(int pos) {
    if (isEmpty() || pos < 0 || pos > top) {
      cout << "Invalid position or stack underflow" << endl;
      return 0;
    } else {
      return arr[pos];
    }
  }

  //  Changing the value inside the stack/array
  void change(int pos, int val) {
    if (pos < 0 || pos > top) {
      cout << "Invalid position!" << endl;
    } else {
      arr[pos] = val;
      cout << "The Value is changed at location " << pos << endl;
    }
  }

  // Display stack elements
  void display() {
    if (isEmpty()) {
      cout << "Stack is empty" << endl;
    } else {
      cout << "All values in the Stack are" << endl;
      for (int i = top; i >= 0; i--) {
        cout << arr[i] << endl;
      }
    }
  }

  // Search operation
  int search(int val) {
    for (int i = 0; i <= top; i++) {
      if (arr[i] == val) {
        return i;
      }
    }
    return -1; // Not found
  }

  // Update at any position
  void update_At_Position(int pos, int val) {
    if (pos < 0 || pos > top) {
      cout << "Invalid position" << endl;
    } else {
      arr[pos] = val;
      cout << "Value updated at position " << pos << endl;
    }
  }

  // Insert at any position
  void insert_At_Position(int pos, int val) {
    if (isFull()) {
      cout << "Stack overflow" << endl;
    } else {
      if (pos < 0 || pos > top + 1) {
        cout << "Invalid position" << endl;
      } else {
        top++;
        for (int i = top; i > pos; i--) {
          arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        cout << "Value inserted at position " << pos << endl;
      }
    }
  }

  // Delete from beginning
  void delete_From_Beginning() {
    if (isEmpty()) {
      cout << "Stack underflow" << endl;
    } else {
      for (int i = 0; i < top; i++) {
        arr[i] = arr[i + 1];
      }
      arr[top] = 0;
      top--;
      cout << "Deleted from beginning" << endl;
    }
  }

  //  Delete from end
  void delete_From_End() {
    if (isEmpty()) {
      cout << "Stack underflow" << endl;
    } else {
      arr[top] = 0;
      top--;
      cout << "The item deleted from the  end" << endl;
    }
  }

  // Delete from any position
  void delete_From_Position(int pos) {
    if (isEmpty()) {
      cout << "Stack underflow" << endl;
    } else {
      if (pos < 0 || pos > top) {
        cout << "Invalid position" << endl;
      } else {
        for (int i = pos; i < top; i++) {
          arr[i] = arr[i + 1];
        }
        arr[top] = 0;
        top--;
        cout << " item Deleted from position " << pos << endl;
      }
    }
  }
};

int main() {
  Stack s1;
  int option, position, value;

  // Creating menu, giving the number to every option 1 onward; when 0, exit the application
  do {
    cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. peek()" << endl;
    cout << "6. count()" << endl;
    cout << "7. change()" << endl;
    cout << "8. display()" << endl;
    cout << "9. Search()" << endl;
    cout << "10. Update at any position" << endl;
    cout << "11. Insert at any position" << endl;
    cout << "12. Delete from beginning" << endl;
    cout << "13. Delete from end" << endl;
    cout << "14. Delete from any position" << endl;
    cout << "15. Clear Screen" << endl << endl;

    cin >> option;
    switch (option) {
      case 0:
        break;
      case 1:
        cout << "Now enter an item to push in the stack" << endl;
        cin >> value;
        s1.push(value);
        break;
      case 2:
        cout << "Now Pop Function is Called - Popped Value: " << s1.pop() << endl;
        break;
      case 3:
        if (s1.isEmpty())
          cout << "Stack is Empty" << endl;
        else
          cout << "Stack is not Empty" << endl;
        break;
      case 4:
        if (s1.isFull())
          cout << "Stack is Full" << endl;
        else
          cout << "Stack is not Full" << endl;
        break;
      case 5:
        cout << "Enter position of item you want to peek: " << endl;
        cin >> position;
        cout << "Peek Function Called - Value at position " << position << " is " << s1.peek(position) << endl;
        break;
      case 6:
        cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
        break;
      case 7:
        cout << "Change Function Called - " << endl;
        cout << "Enter position of item you want to change : ";
        cin >> position;
        cout << endl;
        cout << "Enter value of item you want to change : ";
        cin >> value;
        s1.change(position, value);
        break;
      case 8:
        cout << "Display Function Called - " << endl;
        s1.display();
        break;
      case 9:
        cout << "Enter value to search: ";
        cin >> value;
        position = s1.search(value);
        if (position != -1)
          cout << "Value found at position " << position << endl;
        else
          cout << "Value not found" << endl;
        break;
      case 10:
        cout << "Enter position to update: ";
        cin >> position;
        cout << "Enter new value: ";
        cin >> value;
        s1.update_At_Position(position, value);
        break;
      case 11:
        cout << "Enter position to insert: ";
        cin >> position;
        cout << "Enter value to insert: ";
        cin >> value;
        s1.insert_At_Position(position, value);
        break;
      case 12:
        s1.delete_From_Beginning();
        break;
      case 13:
        s1.delete_From_End();
        break;
      case 14:
        cout << "Enter position to delete: ";
        cin >> position;
        s1.delete_From_Position(position);
        break;
      case 15:
        system("cls");
        break;
      default:
        cout << "You have entered wrong option number so enter Proper Option number " << endl;
    }
  } while (option != 0);

  return 0;
}

