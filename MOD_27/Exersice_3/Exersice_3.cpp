#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Branch
{
    Branch* parent;
public:
    std::vector<Branch*> children;
    std::string elf;
    Branch(Branch* p = nullptr) : parent(p), elf("None") {}
    void addChild(Branch* c) { children.push_back(c); }
    void setElf(std::string name) { elf = name; }
    Branch* findElf(const std::string& name) 
    {
        if (elf == name) return this;
        for (auto c : children) 
        {
            Branch* res = c->findElf(name);
            if (res) return res;
        }
        return nullptr;
    }
    Branch* getTopBranch() 
    {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return parent;
        return parent->getTopBranch();
    }
    int countElves()
    {
        int cnt = (elf != "None");
        for (auto c : children) cnt += c->countElves();
        return cnt;
    }
};

int main() 
{
    srand(time(0));
    std::vector<Branch*> trees;

    for (int t = 0; t < 5; t++)
    {
        Branch* tree = new Branch();
        int bigCount = 3 + rand() % 3;
        for (int b = 0; b < bigCount; b++) 
        {
            Branch* big = new Branch(tree);
            tree->addChild(big);
            int midCount = 2 + rand() % 2;
            for (int m = 0; m < midCount; m++)
            {
                Branch* mid = new Branch(big);
                big->addChild(mid);
            }
        }
        trees.push_back(tree);
    }

    std::cout << "Enter the names of the elves (None - skip):\n";
    for (auto tree : trees) 
    {
        for (auto big : tree->children)
        {
            std::string name;
            std::cout << "Elf on a big branch: "; std::cin >> name;
            big->setElf(name);
            for (auto mid : big->children)
            {
                std::cout << "Elf on a middle branch: "; std::cin >> name;
                mid->setElf(name);
            }
        }
    }

    std::cout << "Enter the elf name to search: ";
    std::string target; std::cin >> target;
    for (auto tree : trees)
    {
        Branch* found = tree->findElf(target);
        if (found)
        {
            Branch* top = found->getTopBranch();
            std::cout << "At the elf's " << target << " neighbors on a large branch: " << top->countElves() - 1 << std::endl;
        }
    }
}
