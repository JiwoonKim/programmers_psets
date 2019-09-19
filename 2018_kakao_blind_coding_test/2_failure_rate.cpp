/**
 *  [2] 실패율
 *      - 전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 주어질 때, 
 *        실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 반환하기
 *      - Reference: https://programmers.co.kr/learn/courses/30/lessons/42889
 * 
 * 
 *  * Solution
 * 
 * 
 *  ** What I learned
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
vector<float> failures(502);

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // 각 스테이지마다 사람 수 기록
    vector<int> ppl_count(N + 2, 0);
    for (int stage : stages) {
        ppl_count[stage]++;
    }
    
    // 각 스테이지마다 실패율 계산하기
    int total = stages.size();
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (total - sum <= 0 || ppl_count[i] == 0) {
            failures[i] = 0;
        }
        else {
            failures[i] = (float)ppl_count[i] / (float)(total - sum);
        }
        sum += ppl_count[i];
    }
    
    // 스테이지 실패율을 바탕으로 내림차순으로 정렬하기
    
    for (int i = 1; i <= N; i++) {
        answer.push_back(i);
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}

/**
 *  도움 함수:
 */
bool cmp(const int& u, const int& v) {
    if (failures[u] == failures[v]) {
        return (u < v);
    }
    return (failures[u] > failures[v]);
}