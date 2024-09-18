import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    static int l, c;
    static char[] arr, password;
    static StringBuilder sb = new StringBuilder();

    // 깊이 우선 탐색 (DFS)로 암호 생성
    public static void dfs(int depth, int index) {
        // 길이가 l인 암호가 완성되었을 때
        if (depth == l) {
            int vowel = 0, consonant = 0;
            // 모음과 자음의 개수를 카운트
            for (int i = 0; i < l; i++) {
                switch (arr[i]) {
                    case 'a': case 'e': case 'i': case 'o': case 'u':
                        vowel++;
                        break;
                    default: consonant++;
                        break;
                }
            }
            // 모음 1개 이상, 자음 2개 이상일 때만 유효한 암호로 간주
            if (vowel > 0 && consonant >= 2) {
                sb.append(arr).append("\n");
            }
            return;
        }
        // 가능한 문자를 선택하여 암호를 생성
        for (int i = index; i < c; i++) {
            arr[depth] = password[i];  // 선택한 문자를 arr에 넣음
            dfs(depth + 1, i + 1);  // 다음 문자 선택
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        l = Integer.parseInt(st.nextToken());  // 암호의 길이
        c = Integer.parseInt(st.nextToken());  // 주어진 문자 수
        arr = new char[l];  // 암호를 담을 배열
        password = new char[c];  // 주어진 문자들을 담을 배열

        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < c; i++) {
            password[i] = st.nextToken().charAt(0);  // 문자를 배열에 저장
        }
        Arrays.sort(password);  // 사전순 출력을 위해 정렬

        dfs(0, 0);  // 깊이 우선 탐색 시작
        System.out.print(sb);  // 결과 출력
    }
}