By mostafijur721, contest: Teza Round 1 (Codeforces Round 1015, Div. 1 + Div. 2), problem: (B) MIN = GCD, Accepted, #, Copy
import sys
import math
 
input_data = sys.stdin.read().split()
test_cases_count = int(input_data[0])
index = 1
results = []
 
for _ in range(test_cases_count):
    array_length = int(input_data[index])
    index += 1
    array = list(map(int, input_data[index:index + array_length]))
    index += array_length
    
    min_value = min(array)
    min_value_count = array.count(min_value)
    
    if min_value_count == array_length:
        results.append("Yes")
        continue
    
    if min_value_count > 1:
        results.append("Yes")
        continue
    
    divisible_numbers = [num for num in array if num % min_value == 0 and num != min_value]
    
    if not divisible_numbers:
        results.append("No")
        continue
    
    gcd_result = divisible_numbers[0]
    for num in divisible_numbers[1:]:
        gcd_result = math.gcd(gcd_result, num)
    
    if gcd_result == min_value:
        results.append("Yes")
    else:
        results.append("No")
 
sys.stdout.write("\n".join(results) + "\n")
