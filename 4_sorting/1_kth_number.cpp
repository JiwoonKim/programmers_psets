/**
 *  [문제] K번째 수
 *  : 배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 주어질 때, 
 *    commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열로 반환하기
 *    (Reference: https://programmers.co.kr/learn/courses/30/lessons/42748)
 * 
 * 
 *  [해결 방법]
 *  
 *    (1) 범위 정렬: O(n log n * m) time, O(n * m) extra space
 *        -> 배열을 복사하여 주어진 범위만을 정렬하여 그 중 k번째 수 반환
 * 
 * 
 *  [What I learned]
 * 
 *     ** Sort Range
 *        : 주어진 범위(i, j)만을 정렬하려면 sort(v.begin() + i - 1, v.begin() + j)을 사용하면 된다
 *          -> 단 주어진 배열을 다른 용도로 또, 재차 사용해야 한다면,
 *             반드시 배열을 복사하여 정렬할 것!!
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) 범위 정렬
 */
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto command : commands) {
        // array의 i번째부터 j번째까지 숫자 정렬
        vector<int> temp = array;
        sort(temp.begin() + command[0] - 1, temp.begin() + command[1]);
        // 정렬한 배열에서 k번째 숫자 반환하기
        int k = (command[0] - 1) + command[2] - 1;
        answer.push_back(temp[k]);
        }
    return answer;
}