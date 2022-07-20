// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02 
// ������Ʈ
// 1�� �˰���
// 2020112377 ��μ�
// -----------------------------------------------------------

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include<cmath>
#include <time.h>

using namespace std;

using namespace stdext;

int INF = 987654321; //ó�� �ʱⰪ

int totalsize; //�� ��ü ����
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<pair<double, int>> subwayGraph[750]; //subwayGraph vector double->�Ÿ� int->�� index

map<string, int> split(string input, char delimiter) { //spilt�Լ�
    //input ���� ù��° �ٿ��� ��ü �� �̸��� string ���ٷ� ����-> ������ �������� �̰� �ϳ��ϳ� split�ؼ� map�� �־��ش�.
   map<string, int> result; //split �ؼ� ������ ��� string->�� �̸� int-> �� �ε��� (key�� �� �̸��̰�, value�� �� �ε���)
    stringstream ss(input); 
    string temp; 
    totalsize = 0; //�� ��ü ���� �ʱ�ȭ

    while (getline(ss, temp, delimiter)) {
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end()); //Ȥ�� �𸣴� �� �� ���� ����
        string temp2 = temp + "��"; //�ڿ� ���� �߰� ex)�湫��->�湫�ο� input data ������ 
        result.insert(make_pair(temp2, totalsize)); //map�� insert
        totalsize++;
    }
    return result; //(key: ���̸� value: ��index)�� map�� ��ȯ
} 

void pushv (string input, char delimiter, vector<pair<double, int>> graph[],int n) { //����ö ���� �Ÿ� ������ ���Ϳ� �����ϴ� �Լ�
    //double-> �Ÿ� int->:�� �ε���
    stringstream ss(input);
    string temp;
    int k = 0;

    while (getline(ss, temp, delimiter)) { 
        if (temp == "inf") //inf�̸�
            graph[n].push_back({ 987654321 ,k}); //987654321�� �Ÿ� �ʱ�ȭ 
        else { //�ƴϸ� 
            double d;
            stringstream ssDouble(temp);
            ssDouble >> d; //string->double ��ȯ��
            graph[n].push_back({ 10*d,k }); //10�� ���� �� push ->����: �� ����� ��Ȯ�ϰ� �ϱ� ����
        }
        k++;
    }
}

map<string, int> stationMap;

void fileRead() { //�Ÿ����� �� ���� �о����
    string line;
    ifstream file("subway_distance.txt");
    if (file.is_open()) { //���� ����
        getline(file, line); //�� �̸����� �о����
        stationMap = split(line, '	'); //stationMap�� ���� �� �̸� �����ϱ�

        int j = 0;
        while (getline(file, line)) { //�� �� �Ÿ� ���� �޾ƿ���
            pushv(line, '	', subwayGraph, j); //subwayGraph�� ���� ���� �Ÿ� �����ϱ�
            j++;
        }
        file.close(); //���� �ݱ�
    }
}
//---------------------------------------------------------------------------------------------------------------------------input ������ ó�� ����


vector<double> dijkstra(int startStation, int N, vector<pair<double, int>> graph[]){ 
    //startStation�� �������� ������ ��� �������� �ִܰŸ� vector�� ��ȯ
    //�̶� startStation�� ���� index�� �޾ƿ´� ! ���� index�� ó���� ���� �� map�� ����� index
    //N: ��ü ���� ����, graph: ���� �Ÿ� ���� ������ִ� �׷���
    //���� ��� �湫�ο��� �Է����� ������ �湫�ο��������� ������ ��ü �������� �ִܰŸ� vector�� ��ȯ�� �ȴ�.
    vector<double> dist(N, INF); //��ȯ�ϴ� �ִܰŸ� vector
    priority_queue<pair<double, int>> prq;  //�켱���� ť double->�Ÿ� int->�� �ε���

    //����
    dist[startStation] = 0;  //�ڱ� �ڽŰ��� �Ÿ��� 0
    prq.push(make_pair(0, startStation)); //�ش� ��� �켱���� ť�� �߰�

    while (!prq.empty())
    { //ť�� ����������� �ݺ�
        double cur_distance = -prq.top().first; //�ּ� ������ �ϱ� ���� �Ÿ��� ������ ó���ؼ� �켱���� ť�� �־��� ������ �ٽ� �Ÿ��� ��ȯ�� �� (-)�� �� �޾��־�� ��
        int cur_station= prq.top().second;  //���� �� index
        prq.pop(); //pop

        //�켱���� ť�̰�, �Ÿ��� ����ó���ؼ� �־��־����Ƿ� �Ÿ��� ���� ������� �ڵ� ����.
        //->���� ���� ���� ����� �Ÿ��� �ִ� ������ Ž��

        if (dist[cur_station] < cur_distance)
            continue; //�ִ� ��ΰ� �ƴϸ� �н�

        for (int i = 0; i < graph[cur_station].size(); i++)
        {
            int next_station = graph[cur_station][i].second;  //�湮�� �� index
            double next_distance = cur_distance + graph[cur_station][i].first; //�湮�� �� �Ÿ� 

            if (next_distance< dist[next_station]) //�� ���� ��쿡�� -> �� �ִܰŸ��� ���ŵ� ��쿡��!
            {
                dist[next_station] = next_distance; //�ִ� �Ÿ� vector ����
                prq.push(make_pair(-next_distance,next_station));  //�켱���� ť�� �߰�
            }
        }
    }
    return dist;  
}

int main() {
    clock_t start, end;

    fileRead(); //subway ���� �б�

    int n; //��� ��


    ifstream file("input600.txt"); //����� ���� �б� -->input 50~600�� �Է¹޴´�
    vector <string> inputStation;
    vector<double>result;
    string buffer;
    if (file.is_open()) {
        file >> n; //��� �� �Է�
        for (int i = 0; i < n; i++) {
            file >> buffer;
            inputStation.push_back(buffer); //�������ŭ  �� �̸� �Է¹ޱ�
        }
        file.close();
    }

    cout << "[input 600] "<< endl; //��ǲ�� ���� �ٲپ� �־�� �� input 50~600
    vector<vector<double>> v(n); //��� �� �Ÿ� ���� 2���� vector
    //���� �� ����: ����� �� ����/ ���� �� ����: ��ü �� ����

    start = clock(); //�˰��� ����ð� ����
    for (int i = 0; i < n; i++) {
        v[i] = vector<double>(); //������ double ����
    }
    for (int i = 0; i < n; i++) {//�Է¹��� ��� �� ��ŭ
//cout << stationMap.find(inputStation[i])->first;
        result = dijkstra(stationMap.find(inputStation[i])->second, totalsize+1, subwayGraph); //�Է¹��� �����κ��� ������ ��� �������� �ִ� �Ÿ��� ����
        for (int j = 0; j < result.size(); j++)
        {
            v[i].push_back(result[j]); //vector �� Ǫ��
        }
    }

    //-------------------------------------------------------------------------�Է¹��� �����κ��� ������ ��� �������� �ִܰŸ� vector �� ����
  
    priority_queue<double> pq;
    vector<double> midium; //�߾Ӱ� vector
    double psum;
    for (int i = 0; i < totalsize; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(v[j][i]); //'��'�� �������� ����� ��� �켱���� ť�� push
            if (j == n - 1) {
                for (int k = 0; k < (n / 2)-1; k++) { //�켱���� ť�� �߰����� ��� pop
                    pq.pop();
                }
                psum = 0.000000;
                psum += pq.top();
                pq.pop();
                psum += pq.top();
                midium.push_back(psum / 2);  //�Է¹޴� �����ʹ� 50 �����̹Ƿ� ��� ¦��, ���� �߰� �� ���� ���� ���ؼ� ������ 2�� ���־�� ��
                while (!pq.empty()) { //�� �����
                    pq.pop();
               }
            }

        }
    }

    double medmin = midium[0];
    for (int i = 1; i < midium.size(); i++) {
        if (medmin > midium[i]) {
            medmin = midium[i];
        } //�߾Ӱ����� �ּ� ã��
    }

    vector<int> medminIndex; //�߾Ӱ��� ���� ���ϼ��� �ֱ� ������ ���� �߾Ӱ��� ������ �ε����� ���縦 �ؾ� ��
    for (int i = 0; i < midium.size(); i++) {
        if (midium[i] == medmin) { //���� ���
            medminIndex.push_back(i); //vector�� �߰�
        }
    }

    vector <string> mediumresult; //���� �ּ� �ε����� ���� �� �̸� vecotr
    map<string, int>::iterator iter5;
    for (int i = 0; i < medminIndex.size(); i++) {
        for (iter5 = stationMap.begin(); iter5 != stationMap.end(); iter5++) { //�� �̿��ؼ� key ã�� �� �ε����� �̿��ؼ� �� �̸� ã��
            if ((iter5->second) == medminIndex[i]) {
                mediumresult.push_back(iter5->first);
            }
        }
    }

    cout << "ù ��° �˰����� ����� ���� �߰� ���� ����  ";
    for (int i = 0; i < mediumresult.size(); i++) {
        cout << mediumresult[i] << "  ";
    }
    cout << "�Դϴ�";
    cout << endl;
   
    end = clock(); //�ð� ���� ��

    double clockresult = (double)(end - start);

   cout << "�˰��� ���� �ð��� : ";
   cout << clockresult;
}

