#include <iostream>
#include <vector>

class Row
{
private:
    std::vector<int> vec;
    int selector = 0;

public:
    void AddItem(int n)
    {
        vec.push_back(n);
    }

    int GetSelectedItem()
    {
        return vec[selector];
    }

    int GetSelector()
    {
        return selector;
    }

    void SetSelector(int n)
    {
        selector = n;
    }

    void MoveSelectorRight()
    {
        selector++;
    }

    int GetArraySize()
    {
        return vec.size();
    }
};

class PermMachine
{
private:
    std::vector<Row*> arrRows;
    int totalCombinations = 0;

public:
    void AddVector(Row* rowPtr)
    {
        rowPtr->SetSelector(0);
        arrRows.push_back(rowPtr);
    }

    void PrintCombination()
    {
        for (int i = 0; i < arrRows.size(); i++)
        {
            std::cout << arrRows[i]->GetSelectedItem() << " ";
        }

        totalCombinations++;
        std::cout << " - combination #" << totalCombinations;
        std::cout << std::endl;
    }

    bool MoveSelectors()
    {
        for (int i = arrRows.size() - 1; i >= 0; i--)
        {
            int lastIndex = arrRows[i]->GetArraySize() - 1;

            if (arrRows[i]->GetSelector() <= lastIndex - 1)
            {
                // set movable selector to the right
                arrRows[i]->MoveSelectorRight();

                // set lower selectors back to starting point
                for (int k = i + 1; k < arrRows.size(); k++)
                {
                    arrRows[k]->SetSelector(0);
                }

                return true;
            }
        }

        return false;
    }

    void PrintAll()
    {
        totalCombinations = 0;

        while (true)
        {
            PrintCombination();

            if (MoveSelectors())
            {
                // repeat until all selectors are NOT movable
            }
            else
            {
                break;
            }
        }

        std::cout << "total combinations: " << totalCombinations << std::endl;
    }
};

int main()
{
    // create sample arrays
    Row r0;
    Row r1;
    Row r2;
    Row r3;
    Row r4;

    r0.AddItem(0);
    r0.AddItem(1);
    r0.AddItem(2);
    r0.AddItem(3);

    r1.AddItem(0);
    r1.AddItem(1);
    r1.AddItem(2);
    r1.AddItem(3);

    r2.AddItem(0);
    r2.AddItem(1);
    r2.AddItem(2);
    r2.AddItem(3);

    r3.AddItem(0);
    r3.AddItem(1);
    r3.AddItem(2);
    r3.AddItem(3);

    r4.AddItem(0);
    r4.AddItem(1);
    r4.AddItem(2);
    r4.AddItem(3);

    // add to the machine
    PermMachine pm;

    pm.AddVector(&r0);
    pm.AddVector(&r1);
    pm.AddVector(&r2);
    pm.AddVector(&r3);
    pm.AddVector(&r4);

    // print all combinations
    pm.PrintAll();
}