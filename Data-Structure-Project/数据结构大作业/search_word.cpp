/**
 * �ĵ������ļ���ȡ�ķ�ʽд��,���Լ���ʱû�취����дһ�����ķִʳ�����Ŀǰֻ֧��Ӣ���ĵ���
 * ���ű�ͨ��multimap������
**/
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;
//�洢�����б���Ϣ����:TF,pos


struct DocMes 
{
    int TF = 0;      //��Ƶ
    vector<int> pos;     //���ĵ����ֵ�λ��
};
typedef map<string, map<int, DocMes>> IndexMap;  //����multiMap����ͨ�������ҵ���Ӧ�ı� IndexMap[��][j] �������idΪj���ĵ��ĺδ���
typedef map<int, DocMes> invertMap;//�����б�ͨ��int�ҵ�

//�����������������ͬ�ļ��е�1.txt 2.txt 3.txt�����ĵ����ִʣ���¼����������Ӧ�����б���Ϣ

void CreateIndex(IndexMap& index) 
{
    string path[10] = { "apple.txt","cherry.txt","grape.txt","mangosteen.txt","orange.txt","peach.txt","pear.txt","pineapple.txt","pomelo.txt","watermelon.txt" };
    //������txt�ĵ�
    ifstream fileIn;
    for (int i = 0; i <= 9; i++) 
    {
        string filepath = path[i];
        fileIn.open(filepath);
        string temp;
        int posNum = 0;
        while (fileIn >> temp) 
        {
            posNum++;//��¼λ��
            //judge(temp);  //����temp
            //iֵΪ�ĵ��ı��
            index[temp][i].TF++;
            index[temp][i].pos.push_back(posNum);
        }
        fileIn.close();
    }
}

//��ѯ����
void queryProcess(IndexMap& index) 
{
    string query;
    cout << "Look up your words:" << endl;
    while (true) 
    {
        cout << ">>";
        cin >> query;
        if (index.find(query) == index.end()) 
        {
            cout << "ERROR: Can't find " << query << " ! ,please check up your words" << endl;
            continue;
        }

        invertMap::iterator iter;//�õ�������ȡÿһ������
        iter = index[query].begin();
        while (iter != index[query].end()) 
        {
            cout << iter->first << ".txt : ���ִ���=" << iter->second.TF << " ; pos = < ";
            int size = iter->second.pos.size();
            for (int i = 0; i < size; i++)
            {
                cout << iter->second.pos[i] << " ";
            }
            cout << " >" << endl;
            iter++;
        }
    }
}

int main() {
    IndexMap invertIndex;
    cout << "Creating Indexs:######" << endl;
    CreateIndex(invertIndex);
    cout << "Creat Indexs successfully!" << endl;
    queryProcess(invertIndex);
    //getchar();
    return 0;
}