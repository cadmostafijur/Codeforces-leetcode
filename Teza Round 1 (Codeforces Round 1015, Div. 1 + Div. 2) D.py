By mostafijur721, contest: Teza Round 1 (Codeforces Round 1015, Div. 1 + Div. 2), problem: (D) Arcology On Permafrost, Accepted, #, Copy
import sys
 
def solve():
    input_data = sys.stdin.read().strip().split()
    
    if not input_data:
        return
    
    num_cases = int(input_data[0])
    current_idx = 1
    final_output = []
 
    for _ in range(num_cases):
        total_elements = int(input_data[current_idx])
        part_count = int(input_data[current_idx + 1])
        max_count = int(input_data[current_idx + 2])
        current_idx += 3
 
        first_limit = total_elements // (part_count + 1)
        second_limit = total_elements - part_count * max_count
        min_limit = min(first_limit, second_limit)
 
        result_list = [min_limit] * total_elements
 
        for val in range(min_limit):
            left_pos = val
            right_pos = total_elements - min_limit + val
            interval_gap = right_pos - left_pos
            step_size = interval_gap // part_count if part_count != 0 else 0
 
            for step in range(part_count+1):
                current_pos = left_pos + step * step_size
                if current_pos > right_pos:
                    current_pos = right_pos
                result_list[current_pos] = val
 
        final_output.append(" ".join(map(str, result_list)))
 
    sys.stdout.write("\n".join(final_output))
 
if __name__ == "__main__":
    solve()
