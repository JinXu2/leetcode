#include <iostream>
using namespace std;

//���鼯�Ƕ����� ���еĲ���
class UnionFind{
public:
    vector<int> parent;

    //��ʼ��
    UnionFind(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    //�ϲ�
    void unionSet(int a,int b)
    {
        parent[find(a)]=find(b);
    }

    //����
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

        //���ȸ�ÿһ�������ţ�ͬʱ��ÿһ�����������û�����
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

        //��ÿ��������кϲ�
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

        //��ÿ�������е����䶼����һ��
        map<int, vector<string>> indexToEmails;
        for(auto& [email, _]:emailToIndex)
        {
            int index=uf.find(emailToIndex[email]);
            vector<string>& account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index]=account;
        }

        //����� ���û����ֹ���������������
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
