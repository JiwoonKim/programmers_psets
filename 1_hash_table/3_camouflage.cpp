/**
 *  [문제] 위장
 *  : 스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때,
 *    서로 다른 옷의 조합의 수를 반환하기
 *    - 단, 최소 한 개의 의상은 입어야 한다
 *    - clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있으며, 같은 이름을 가진 의상은 존재하지 않는다
 * 
 *    (Reference: https://programmers.co.kr/learn/courses/30/lessons/42578)
 * 
 * 
 *  [해결 방법]
 *  
 *    (1) 조합 직접 다 만들어 세기: 
 * 
 *    (2) 
 * 
 * 
 *  [What I learned]
 * 
 *     ** Counting Principle
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
vector<vector<int>> combinations;
int solution(vector<vector<string>> clothes) {
    
    // 카테고리별로 옷 개수 세기: (카테고리, 개수)
    vector<string> category_list;
    unordered_map<string, int> category_count;
    for (auto pair : clothes) {
        string category = pair[1];
        if (category_count.count(category) == 0) {
            category_count[category] = 1;
            category_list.push_back(category);
        } else {
            category_count[category]++;
        }
    }
    
    // 카테고리로 만들 수 있는 모든 조합 구하기
    vector<int> empty = {};
    combine(empty, 0, category_list.size() - 1);
    
    // 각 조합에서 나올 수 있는 경우의 수의 합 구하기
    int answer = 0;
    for (auto comb : combinations) {
        int count = 1;
        for (int index : comb) {
            string category = category_list[index];
            count *= category_count[category];
        }
        answer += count;
    }
    return answer;
}

/**
 *  도움 함수: 가능한 모든 길이의 조합 다 만들기
 */
void combine(vector<int> prefix, int start, int end) {
    // recursive case:
    for (int i = start; i <= end; i++) {
        // 사용가능한 다음 숫자를 붙인 조합 저장
        prefix.push_back(i);
        combinations.push_back(prefix);
        // 사용가능한 숫자가 더 있다면, 재귀호출하여 숫자 더 붙일 수 있는만큼 붙이기
        if (i < end) {
            combine(prefix, i + 1, end);
        }
        // 붙였던 숫자 다시 떼기
        prefix.pop_back();
    }
}

/**
 *  
 */
int solution(vector<vector<string>> clothes) {

    // 카테고리별로 옷 개수 세기: (카테고리, 개수)
    unordered_map<string, int> category_count;
    for (auto pair : clothes) {
        string category = pair[1];
        if (category_count.count(category) == 0) {
            category_count[category] = 1;
        } else {
            category_count[category]++;
        }
    }

    /* 서로 다른 옷의 조합의 수 계산하기
       -> 각 카테고리의 (의상 수 + 1)을 곱해나가기
          : 각 의상 입는 경우 + 의상종류 자체를 입지 않는 경우
    */
    int answer = 1;
    for (const auto& kv : category_count) {
        answer *= (kv.second + 1);
    }
    
    // 의상 아무것도 입지 않는 경우 (벌거벗는 경우) 제외하기
    answer = answer - 1;
    return answer;
}