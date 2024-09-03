import sys
input = sys.stdin.readline
target = int(input())  # 목표 채널 번호
n = int(input())       # 고장난 버튼의 개수
broken = list(map(int, input().split()))   # 고장난 버튼의 리스트

min_count = abs(100 - target)   # 최소 버튼 누름 횟수(절대값 반환)

for nums in range(1000001):     # 0~1000000까지의 모든 채널 확인(채널 번호 6자리)
    nums = str(nums)       # 현재 채널 번호를 문자열로 저장

    for j in range(len(nums)):  # 채널 번호의 각 자릿수 확인
        if int(nums[j]) in broken:  # 해당 자릿수가 고장난 버튼에 포함된다면
            break   # 채널 선택 중지

        elif j == len(nums) - 1:    # 채널 번호가 모두 고장나지 않은 경우
            min_count = min(min_count, abs(int(nums) - target) + len(nums))
            # 목표 채널까지의 거리와 채널 번호를 입력하는 데 필요한 버튼 횟수를 계산하여 min_count 업데이트

print(min_count)

sys.exit(0)