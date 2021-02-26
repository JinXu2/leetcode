#include <iostream>
using namespace std;

//并查集是对邮箱 进行的操作
class UnionFind{
public:
    vector<int> parent;

    //初始化
    UnionFind(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    //合并
    void unionSet(int a,int b)
    {
        parent[find(a)]=find(b);
    }

    //查找
    int find(int index)
    {
        if(parent[index]!=index)
        {
            parent[index]=find(parent[index]);
        }
        return parent[index];
    }
};



class Solution{
public:
      vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
      {
        map<string,int> emailToIndex;
        map<string,string> emailToName;
        int emailCount=0;

        //首先给每一个邮箱标号，同时将每一个邮箱与其用户相连
        for(auto& account :accounts)
        {
            string& name=account[0];
            int size=account.size();
            for(int i=1;i<size;i++)
            {
                string& email=account[i];
                if(!emailToIndex.count(email))
                {
                    emailToIndex[email]=emailCount++;
                    emailToName[email]=name;
                }
            }
        }

        //对每组邮箱进行合并
        UnionFind uf(emailCount);
        for(auto& account: accounts)
        {
            string& firstEmail =account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size=account.size();
            for(int i=2;i<size;i++)
            {
                string& nextEmail = account[i];
                int nextIndex=emailToIndex[nextEmail];
                uf.unionSet(firstIndex,nextIndex);
            }
        }

        //将每个集合中的邮箱都放在一起
        map<int, vector<string>> indexToEmails;
        for(auto& [email, _]:emailToIndex)
        {
            int index=uf.find(emailToIndex[email]);
            vector<string>& account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index]=account;
        }

        //输出答案 与用户名字关联起来，并排序
        vector<vector<string>> merged;
        for(auto& [_,emails] : indexToEmails)
        {
            sort(emails.begin(),emails.end());
            string& name= emailToName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for(auto& email:emails)
            {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }

        return merged;


      }

};
