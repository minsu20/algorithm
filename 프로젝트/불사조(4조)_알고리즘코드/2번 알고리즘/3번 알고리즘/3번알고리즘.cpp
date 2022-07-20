// -----------------------------------------------------------
// ��ǻ�;˰���� �ǽ�-02
// ������Ʈ
// 3�� �˰���
// 2018112025 ���͹�
// -----------------------------------------------------------
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;
//�Է� ���� ������ �� ����ö ����
#define stationCount "100"
#define MAX 100

clock_t start, end_time = clock();

//��� ����ö �� ��ġ �Է¹ޱ�
map<string, vector<string> > fileInput(string path) {
    map <string, vector <string> > locationData;
    ifstream readFile (path);
    string stationName;
    string lat;
    string lon;

    if (readFile.is_open()) {
        for(int i = 0; i < 640; i ++) {
            readFile >> stationName;
            readFile >> lat;
            readFile >> lon;
            //�� �̸�, ����, �浵 �� ���� ���ۿ��� �ҷ����� locationData�� �����س��� ������ map���·� ����
            locationData[stationName + "��"] = vector<string> {lat, lon};
        }
    }
    //���Ͽ��� �ҷ��� ��ü �� ������ ��ȯ
    return locationData;
}

//inputfile�� �ҷ����� �Լ�
vector <string> userfileInput(string path) {
    vector <string> userData;
    ifstream readFile (path);
    string stationName;

    if (readFile.is_open()) {
        for(int i = 0; i < stoi(stationCount) + 1; i ++) {
            readFile >> stationName;
            //���ϰ����� ���Ե��� �ʰ� ����ó��
            if (stationName != stationCount) {
                //�ҷ��� ������ userData���Ϳ� ����
                userData.push_back(stationName);
            }
        }
    }
    //���Ͽ��� �ҷ��� ��ü ���� �� ������ ��ȯ
    return userData;
}

//������ �����Լ�
//�˰��� ����Ҷ�, ù �񱳰��� �������� �ֱ� ���ؼ� �����.
int makeRand() {
    srand((unsigned int)time(NULL));
    int randnum = rand();
    randnum = randnum % 9;
    return randnum;
}

//�˻��� �Ϸ�� �� ���� ���� ����ϴ� �Լ�
void printStation(double lat, double lon, map<string, vector<string> > sData) {
    double minLati = -1;
    double minLong = -1;
    //���ͷ����͸� �̿��ؼ� map�� value���� �̵���Ű�� �������� ������ ��� �˻�
    for (auto iter = sData.begin(); iter != sData.end(); ++iter){
        double latNum = stod(iter -> second[0]);
        double lonNum = stod(iter -> second[1]);
        //�˻������ ���� ���� �浵�� ���� �����浵�� ����
        //0.01 == 1km ������, �˻� ����� ��ǥ�� �����浵�� 1km�̳��� �ִ� ��� ������ �����.
        if (latNum + 0.01 >= lat && latNum - 0.01 <= lat){
            if(lonNum + 0.01 >= lon && lonNum - 0.01 <= lon){
                string data = iter -> first;
                cout << "[input " << MAX << "]" << endl;
                cout << "�� ��° �˰����� ����� ���� �߰� ���� ���� " << data << "�Դϴ�." << endl;
            }
        }
        }
    end_time = clock();
}


//���� �˰��� ���� �κ�
void distributionSolution(map<string, vector<string>> sData, vector<string> uData, int k) {
    vector<pair<double, double>> means;
    int group[MAX];

    //������ �ʱⰪ ����
    for(int i = 0; i < k; i ++) {
        //0 Ȥ�� 1�� �ε����� ó��
        int ran = makeRand();
        //sData�� �� �̸��� ���� �����浵�� �����ֱ� ������, userData�� �ε����� 0~9�� �������� �Է��ؼ� ���̸��� �̾Ƴ�
        //�̾Ƴ� �̸��� �������� ù means�� ������
        means.push_back(make_pair(stod(sData[uData[ran]][0]), stod(sData[uData[ran]][1])));
    }

    while (true) {
        //�˻��� �Ϸ�� ��� while���� ����� �ϴϱ� flag ����
        bool flag = false;
        //ó����, ��ġ�� �������� group�迭�� �ֺ��ּҰŸ��� ������Ʈ���� �� �־��ִ� ���� (������ K=1�̴ϱ� ��� ������Ʈ�� �� �� ����)
        for (int i = 0; i < uData.size(); i++) {
            //�ּ� �Ÿ��� �ּҰ��� �Ǵ��� ������ �ʱ�ȭ
            double mDistance = MAX;
            int min = -1;

            //k == ���� ���� ������ �߽��� ����
            for(int j = 0; j < k; j++) {
                double distance = 0;
                //(x2-x1)^2 + (y2-y1)^2 ���������� �Ÿ������� �̿��ؼ� distance�� ����
                //������ �����̸� ��Ʈó���� ���� �ʿ���� �� ���� ���� �ʾ���.
                distance = pow(means[j].first - stod(sData[uData[i]][0]),2) +  pow(means[j].second - stod(sData[uData[i]][1]),2);
                //�ּҰŸ����� ��� ���� �Ÿ��� ª�ٸ�, �ּ� �Ÿ��� ��ü ���ְ�, min���� ���� j(�ε���)�� �־���.
                if(distance < mDistance) {
                    mDistance = distance; //�Ÿ�
                    min = j; //��� ���� ���� ����� index������ �ٲپ���
                }
            }
            //�� ��, �������� Kgroup �迭�� min���� �־���
            group[i] = min;
        }

        //k = 1��, ������θ� k�� ������ŭ �迭�� ���� ���� ���� �ٲپ���ߵ����� ������ ������ ����� �ϳ��� ���Ҳ��� �������
        //���� �׷���� ����� ã�����ؼ� ������ �����浵���� ��� ������.
        pair<double, double> temp[1];
        int count[1] = {};
        //���� �������� ������ŭ �ݺ��ϸ�,
        //�� �������� �����浵���� ��� ������
        for(int i = 0; i < uData.size(); i++) {
            count[group[i]]++;
            temp[group[i]].first += stod(sData[uData[i]][0]);
            temp[group[i]].second += stod(sData[uData[i]][1]);
        }
        //��� ���� �����浵���� ���� count(�� ������ i ��)���� ��������
        for(int i = 0; i < k; i++) {
            temp[i].first /= count[i];
            temp[i].second /= count[i];
            //�츮�� k�� 1�̱� ������, ��� ������ �����浵 ���� ���ؼ� �̸� �� �������� �������� ����� ��.
            //������, means�� ��ó�� ���� �ε��� ���� �̿��ؼ� �����س��� ������ �� ���� �ƴ�.
            //�׷��� ��հ��� ���������� �Ǵ��ϱ� ���ؼ� ���ο� ��հ� ���� ����� ���� ������
            //���� ���� ��հ� ���� ����� ���� �������� (10m)�� ����ٸ�, ��հ�(mean)�� ���� �ٲٰ�, �ѹ� �� ������ ������
            if (fabs(temp[i].first - means[i].first) > 0.0001 && fabs(temp[i].second - means[i].second) > 0.0001) {
                flag = true;
                means[i].first = temp[i].first;
                means[i].second = temp[i].second;
            }
        }
        //�������� ������ ���������� �ֺ��� ������ �������
        if (flag == false) {
            printStation(means[0].first, means[0].second, sData);
            break;
        }
    }
}


int main() {
    //���� �ҷ�����
    auto stationData = fileInput("//Users/parkikbum/Desktop/computerAlgorithm/cumputerAlgol/cumputerAlgol/station_location.txt");
    auto peopleData = userfileInput("/Users/parkikbum/Desktop/computerAlgorithm/cumputerAlgol/cumputerAlgol/input100.txt");

    //�˰��� ����
    start = clock();
    distributionSolution(stationData, peopleData, 1);
    cout << "����ð� : " << double(end_time - start) << endl;
}