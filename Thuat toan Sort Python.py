import numpy as np
import time

# Đường dẫn tới tệp chứa dữ liệu
file_path = "Bo du lieu 10.txt"

# Đọc dữ liệu từ tệp văn bản và chuyển đổi thành mảng NumPy
with open(file_path, 'r') as file:
    data = [int(line.strip()) for line in file]

# Chuyển danh sách sang mảng NumPy
arr = np.array(data)

t1 = time.time()
# Sắp xếp mảng
sorted_arr = np.sort(arr)

# In ra số cuối cùng của mảng sau khi đã sắp xếp
print("Last element of the sorted array:", sorted_arr[-1])
t2 = time.time()
print('Elapsed time: {} seconds'.format((t2 - t1)))
