// -----------------------------------------------------------
// 컴퓨터알고리즘과 실습-02 
// 프로젝트
// 1번 알고리즘
// 2020112377 김민수
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

int INF = 987654321; //처음 초기값

int totalsize; //역 전체 개수
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<pair<double, int>> subwayGraph[750]; //subwayGraph vector double->거리 int->역 index

map<string, int> split(string input, char delimiter) { //spilt함수
    //input 파일 첫번째 줄에서 전체 역 이름을 string 한줄로 받음-> 공백을 기준으로 이걸 하나하나 split해서 map에 넣어준다.
   map<string, int> result; //split 해서 나오는 결과 string->역 이름 int-> 역 인덱스 (key는 역 이름이고, value는 역 인덱스)
    stringstream ss(input); 
    string temp; 
    totalsize = 0; //역 전체 개수 초기화

    while (getline(ss, temp, delimiter)) {
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end()); //혹시 모르니 앞 뒤 공백 제거
        string temp2 = temp + "역"; //뒤에 역을 추가 ex)충무로->충무로역 input data 때문에 
        result.insert(make_pair(temp2, totalsize)); //map에 insert
        totalsize++;
    }
    return result; //(key: 역이름 value: 역index)인 map을 반환
} 

void pushv (string input, char delimiter, vector<pair<double, int>> graph[],int n) { //지하철 역간 거리 정보를 벡터에 저장하는 함수
    //double-> 거리 int->:역 인덱스
    stringstream ss(input);
    string temp;
    int k = 0;

    while (getline(ss, temp, delimiter)) { 
        if (temp == "inf") //inf이면
            graph[n].push_back({ 987654321 ,k}); //987654321로 거리 초기화 
        else { //아니면 
            double d;
            stringstream ssDouble(temp);
            ssDouble >> d; //string->double 변환후
            graph[n].push_back({ 10*d,k }); //10을 곱한 뒤 push ->이유: 더 계산을 정확하게 하기 위해
        }
        k++;
    }
}

map<string, int> stationMap;

void fileRead() { //거리정보 역 파일 읽어오기
    string line;
    ifstream file("subway_distance.txt");
    if (file.is_open()) { //파일 열기
        getline(file, line); //역 이름부터 읽어오기
        stationMap = split(line, '	'); //stationMap에 읽은 역 이름 저장하기

        int j = 0;
        while (getline(file, line)) { //역 간 거리 정보 받아오기
            pushv(line, '	', subwayGraph, j); //subwayGraph에 읽은 역간 거리 저장하기
            j++;
        }
        file.close(); //파일 닫기
    }
}
//---------------------------------------------------------------------------------------------------------------------------input 데이터 처리 관련


vector<double> dijkstra(int startStation, int N, vector<pair<double, int>> graph[]){ 
    //startStation을 기준으로 나머지 모든 역까지의 최단거리 vector를 반환
    //이때 startStation은 역의 index를 받아온다 ! 역의 index는 처음에 읽을 때 map에 저장된 index
    //N: 전체 역의 개수, graph: 역간 거리 정보 담겨져있는 그래프
    //예를 들어 충무로역이 입력으로 들어오면 충무로역에서부터 나머지 전체 역까지의 최단거리 vector가 반환이 된다.
    vector<double> dist(N, INF); //반환하는 최단거리 vector
    priority_queue<pair<double, int>> prq;  //우선순위 큐 double->거리 int->역 인덱스

    //시작
    dist[startStation] = 0;  //자기 자신과의 거리는 0
    prq.push(make_pair(0, startStation)); //해당 노드 우선순위 큐에 추가

    while (!prq.empty())
    { //큐가 비어질때까지 반복
        double cur_distance = -prq.top().first; //최소 힙으로 하기 위해 거리를 음수로 처리해서 우선순위 큐에 넣었기 때문에 다시 거리로 반환할 때 (-)을 꼭 달아주어야 함
        int cur_station= prq.top().second;  //현재 역 index
        prq.pop(); //pop

        //우선순위 큐이고, 거리는 음수처리해서 넣어주었으므로 거리가 작은 순서대로 자동 정렬.
        //->시작 역과 가장 가까운 거리에 있는 역부터 탐색

        if (dist[cur_station] < cur_distance)
            continue; //최단 경로가 아니면 패스

        for (int i = 0; i < graph[cur_station].size(); i++)
        {
            int next_station = graph[cur_station][i].second;  //방문한 역 index
            double next_distance = cur_distance + graph[cur_station][i].first; //방문한 역 거리 

            if (next_distance< dist[next_station]) //더 작은 경우에만 -> 즉 최단거리가 갱신된 경우에만!
            {
                dist[next_station] = next_distance; //최단 거리 vector 갱신
                prq.push(make_pair(-next_distance,next_station));  //우선순위 큐에 추가
            }
        }
    }
    return dist;  
}

int main() {
    clock_t start, end;

    fileRead(); //subway 파일 읽기

    int n; //사람 수


    ifstream file("input600.txt"); //사용자 파일 읽기 -->input 50~600을 입력받는다
    vector <string> inputStation;
    vector<double>result;
    string buffer;
    if (file.is_open()) {
        file >> n; //사람 수 입력
        for (int i = 0; i < n; i++) {
            file >> buffer;
            inputStation.push_back(buffer); //사람수만큼  역 이름 입력받기
        }
        file.close();
    }

    cout << "[input 600] "<< endl; //인풋에 따라 바꾸어 주어야 함 input 50~600
    vector<vector<double>> v(n); //결과 역 거리 정보 2차원 vector
    //벡터 행 개수: 사용자 역 개수/ 벡터 열 개수: 전체 역 개수

    start = clock(); //알고리즘 수행시간 측정
    for (int i = 0; i < n; i++) {
        v[i] = vector<double>(); //이차원 double 벡터
    }
    for (int i = 0; i < n; i++) {//입력받은 사람 수 만큼
//cout << stationMap.find(inputStation[i])->first;
        result = dijkstra(stationMap.find(inputStation[i])->second, totalsize+1, subwayGraph); //입력받은 역으로부터 나머지 모든 역까지의 최단 거리를 구함
        for (int j = 0; j < result.size(); j++)
        {
            v[i].push_back(result[j]); //vector 에 푸쉬
        }
    }

    //-------------------------------------------------------------------------입력받은 역으로부터 나머지 모든 역까지의 최단거리 vector 을 구함
  
    priority_queue<double> pq;
    vector<double> midium; //중앙값 vector
    double psum;
    for (int i = 0; i < totalsize; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(v[j][i]); //'열'을 기준으로 나누어서 모두 우선순위 큐에 push
            if (j == n - 1) {
                for (int k = 0; k < (n / 2)-1; k++) { //우선순위 큐를 중간까지 계속 pop
                    pq.pop();
                }
                psum = 0.000000;
                psum += pq.top();
                pq.pop();
                psum += pq.top();
                midium.push_back(psum / 2);  //입력받는 데이터는 50 단위이므로 모두 짝수, 따라서 중간 두 개의 값을 더해서 나누기 2를 해주어야 함
                while (!pq.empty()) { //다 비워줌
                    pq.pop();
               }
            }

        }
    }

    double medmin = midium[0];
    for (int i = 1; i < midium.size(); i++) {
        if (medmin > midium[i]) {
            medmin = midium[i];
        } //중앙값에서 최소 찾기
    }

    vector<int> medminIndex; //중앙값이 여러 개일수도 있기 때문에 같은 중앙값을 가지는 인덱스를 조사를 해야 함
    for (int i = 0; i < midium.size(); i++) {
        if (midium[i] == medmin) { //같은 경우
            medminIndex.push_back(i); //vector에 추가
        }
    }

    vector <string> mediumresult; //가장 최소 인덱스를 가진 역 이름 vecotr
    map<string, int>::iterator iter5;
    for (int i = 0; i < medminIndex.size(); i++) {
        for (iter5 = stationMap.begin(); iter5 != stationMap.end(); iter5++) { //값 이용해서 key 찾기 즉 인덱스를 이용해서 역 이름 찾기
            if ((iter5->second) == medminIndex[i]) {
                mediumresult.push_back(iter5->first);
            }
        }
    }

    cout << "첫 번째 알고리즘을 사용해 구한 중간 지점 역은  ";
    for (int i = 0; i < mediumresult.size(); i++) {
        cout << mediumresult[i] << "  ";
    }
    cout << "입니다";
    cout << endl;
   
    end = clock(); //시간 측정 끝

    double clockresult = (double)(end - start);

   cout << "알고리즘 수행 시간은 : ";
   cout << clockresult;
}

