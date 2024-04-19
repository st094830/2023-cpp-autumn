#include<iostream>


struct Node
{
    int data;
    Node* next;
    //конструкторы(2), деструктор, оператор вывода
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    ~Node() {}
    friend std::ostream& operator<<(std::ostream& stream, Node& node)
    {
        stream << node.data;
        return stream;
    }
};

class LinkedList
{
public:
    LinkedList() : head(nullptr) {};
    ~LinkedList() { dispose(); }
    int Length()
    {
        int length = 0;
        Node* current = head;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }
        return length;
    }
    bool IsEmpty()
    {
        return (head == nullptr);
    }
    void PushHead(int data)
    {
        Node* node = new Node(data);
        InsertNode(0, node);
    }

    //вставляет элемент data на позицию index
    void Insert(int index, int data)
    {
        Node* node = new Node(data);
        InsertNode(index, node);
    }
    void PushTail(int data)
    {
        Insert(Length() - 1, data);
    }

    //извлекает головной элемент
    int PopHead()
    {
        return PopData(ExtractNode(0));
    }

    //извлекает данные из позиции index
    //и удаляет элемент из списка
    int Extract(int index)
    {
        return PopData(ExtractNode(index));
    }
    int PopTail()
    {
        return PopData(ExtractNode(Length() - 1));
    }

    //получает данные из позиции index
    //без удаления из списка
    int Data(int index)
    {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i)
        {
            current = current->next;
        }
        return (current != nullptr ? current->data : 0);
    }
    void swap(int ia, int ib)
    {
        if (ia == ib || !IndexValid(ia) || !IndexValid(ib))
        {
            return;
        }
        if (ia < ib)
        {
            swap(ib, ia);
        }
        Node* nodea = ExtractNode(ia);
        Node* nodeb = ExtractNode(ib);
        if (nodea == nullptr || nodeb == nullptr)
        {
            return;
        }
        InsertNode(ia, nodeb);
        InsertNode(ib, nodea);
    }
    void sort()
    {
        for (int i = Length() - 1; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (Data(j) > Data(j + 1))
                {
                    swap(j, j + 1);
                }
            }
        }
    }
    //оператор вывода в поток
    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
    {
        Node* current = list.head;
        while (current != nullptr)
        {
            stream << *current << " ";
            current = current->next;
        }
        return stream;
    }
private:
    void dispose()
    {
        while (head != nullptr)
        {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }

    //извлекает данные из ноды и удаляет саму ноду
    int PopData(Node* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int res = node->data;
        delete node;
        return res;
    } //!
    void InsertNode(int index, Node* node)
    {
        if (index <= 0 || head == nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index - 1 && current->next != nullptr; ++i)
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
    }//!
    Node* ExtractNode(int index)
    {
        if (!IndexValid(index))
        {
            return nullptr;
        }
        if (index == 0)
        {
            Node* current = head;
            head = head->next;
            return current;
        }
        Node* current = head;
        for (int i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }
        Node* temporary = current->next;
        current->next = temporary->next;
        return temporary;
    }//!
    bool IndexValid(int index)
    {
        if (index < 0)
        {
            return false;
        }
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; ++i)
        {
            current = current->next;
        }
        return current != nullptr;
    }
    Node* head;
};

int main(int argc, char* argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(3, 4);
    std::cout << list << std::endl << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopHead() << " ";
    std::cout << list.Extract(1) << " ";
    std::cout << list.PopTail() << " ";
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl << std::endl;

    list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
    list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;
    return EXIT_SUCCESS;
}
