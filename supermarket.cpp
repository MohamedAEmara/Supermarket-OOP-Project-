//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class Product
{
    private:
        int ProductNumber=0;
        string ProductName="";
        float ProductPrice=0;
        int ProductQuantity=0;

    public:
        void CreateProduct()
        {
            cout << "Enter the Product Number: ";
            cin >> ProductNumber;
            cout << "Enter the Product Name: ";
            cin >> ProductName;
            cout << "Enter the Product Price: ";
            cin >> ProductPrice;
            cout << "Enter the Product Quantity: ";
            cin >> ProductQuantity;
        }
        void ShowInfo()
        {
            cout << "The Product Number is:     " << ProductNumber << endl;
            cout << "The Product Name is:       " << ProductName << endl;
            cout << "The Product Price is:      " << ProductPrice << endl;
            cout << "The Product Quantity is:   " << ProductQuantity << endl;
            cout << "--------------------------------------------------" << endl;
        }
        int GetProductNumber()
        {
            return ProductNumber;
        }
        string GetProductName()
        {
            return ProductName;
        }
        float GetProductPrice()
        {
            return ProductPrice;
        }
        int GetProductQuantity()
        {
            return ProductQuantity;
        }

};

Product MyProduct;
fstream MyFile;
ifstream input;
ofstream output;

void WriteProducts()
{
    MyFile.open("Sample.txt", ios::app);
    MyProduct.CreateProduct();
    MyFile.write((char*)&MyProduct, sizeof(MyProduct));
    MyFile.close();
    cout << endl << endl << "The Product has been created...";
    MyFile.close();
}

void DisplayProducts()
{
    cout << "All the products Info: " << endl;
    input.open("Sample.txt");

    while (input.read((char*)&MyProduct, sizeof(MyProduct)))
    {
        MyProduct.ShowInfo();
    }
    MyFile.close();
}

void SearchProduct(int n)
{
    input.open("Sample.txt");

    int flag = 0;
    while (input.read((char*)&MyProduct, sizeof(Product)))
    {
        if (MyProduct.GetProductNumber() == n)
        {
            MyProduct.ShowInfo();
        }
    }
    MyFile.close();
    if (!flag)
    {
        cout << "\nItem not found :( \n\n";
    }

    MyFile.close();

}


void DeleteProduct()
{
    int num;
    cout << "\n\nPlease enter the product to be deleted..\n";
    cin >> num;
    input.open("Sample.txt");
    fstream f2;
    output.open("Replace.txt");
    output.clear();
    while (input.read((char*)&MyProduct, sizeof(MyProduct)))
    {
        if (MyProduct.GetProductNumber() != num)
        {
            output.write((char*)&MyProduct, sizeof(MyProduct));
        }
    }
  
    input.close();
    output.close();
    MyFile.close();
    f2.close();
    
    //remove("D:\\OOP Projects\\Project 2\\Sample.txt");
    remove("Sample.txt");
    rename("Replace.txt", "Sample.txt");
    //rename("D:\\OOP Projects\\Project 2\\Replace.txt", "D:\\OOP Projects\\Project 2\\Sample.txt");
    
    cout << "\n\nThe product deleted successfully!\n";
}


int main()
{
    char ch;
    do
    {
        cout << "\n\nMain Menu";
        cout << "\n\n\t1.Create Product";
        cout << "\n\n\t2.Display All Products";
        cout << "\n\n\t3.Search";
        cout << "\n\n\t4.Delete Product";
        cout << "\n\n\t5.Exit";
        cout << "\n\n\tPlease Enter Your Choice (1-6):\t";
        cin >> ch;
        
        switch (ch)
        {
        case '1':
            WriteProducts();
            break;
        case '2':
            DisplayProducts();
            break;
        case '3':
            int n;
            cout << "Enter the number of product to search:\t";
            cin >> n;
            SearchProduct(n);
            break;
        case '4':
            DeleteProduct();
            break;
        default:
            cout << "Error!!\n";
            exit(0);
            break;
        }
    } while (ch != 6);


    
}
