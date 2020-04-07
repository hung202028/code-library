# Mảng lưu giá trị chữ tiếng việt của số
arr = ['không', 'một', 'hai', 'ba', 'bốn', 'năm', 'sáu', 'bảy', 'tám', 'chín']


# Hàm xóa tất cả các chữ số zero ở đầu
# Ví dụ khi nhập vào  0003567 sẽ thành 3567
def remove_heading_zeros(num_str: str) -> str:
    return num_str.lstrip("0")


# Hàm xóa kí tự spaces (ở đầu, ở giữa và ở cuối) một chuỗi
# Ví dụ khi nhập 321 456  125   thì sẽ thành 321456125
def remove_spaces(num_str: str) -> str:
    return num_str.strip().replace(' ', '')


# Kiểm tra xem một chuỗi nhập vào có phải là chuỗi gồm số không
# Ví dụ 12456 là chuỗi số,  12i34 không phải là số
def is_valid_number(num_str: str) -> bool:
    if str is None or len(num_str) == 0:
        return False

    for ch in num_str:
        if not ch.isdigit():
            return False

    return True


def read(input_str: str):
    num_str = remove_spaces(input_str)

    is_negative = False
    if num_str.startswith('-'):
        is_negative = True
        num_str = num_str[1:]

    num_str = remove_heading_zeros(num_str)
    if len(num_str) == 0:
        return arr[0]

    if not is_valid_number(num_str):
        exit('Số nhập vào không hợp lệ!')

    n = len(num_str)

    if n == 1:
        result = arr[int(num_str)]
    elif n == 2:
        result = read2(num_str)
    elif n == 3:
        result = read3(num_str)
    elif 4 <= n <= 6:
        result = read_456(num_str)
    elif 7 <= n <= 9:
        result = read_789(num_str)
    else:
        result = read_more(num_str)

    if is_negative:
        result = "ÂM< " + result + " >"

    return result


# đọc số có 2 chữ số
def read2(num_str: str) -> str:
    a = int(num_str[0])
    b = int(num_str[1])

    if num_str == '00':
        return arr[0]
    elif a == 1:
        result = "mười"
        if b != 0:
            result += " lăm" if b == 5 else ' ' + arr[b]
        return result
    elif a == 0:
        return arr[b]
    else:
        result = arr[a] + " mươi"
        if b != 0:
            if b == 5:
                result += " lăm"
            elif b == 1:
                result += " mốt"
            else:
                result += ' ' + arr[b]
        return result


# đọc số có 3 chữ số
def read3(num_str: str) -> str:
    if num_str == '000':
        return ''
    else:
        a = int(num_str[0])
        b = int(num_str[1])
        c = int(num_str[2])

        result = arr[a] + " trăm"
        if b == 0:
            if c != 0:
                return result + " lẻ " + arr[c]
            else:
                return result
        else:
            result += " " + read2(num_str[1:])
            return result


# đọc số có 1 hoặc 2 hoặc 3 chữ số (sử dụng lại kết của của 2 hàm trước)
def read_123(num_str: str) -> str:
    n = len(num_str)
    if n == 1:
        return arr[int(num_str)]
    elif n == 2:
        return read2(num_str)

    return read3(num_str)


# đọc số có 4 hoặc 5 hoặc 6 chữ số
def read_456(num_str: str) -> str:
    if num_str == '000000':
        return ''

    a_str = num_str[0: -3]
    b_str = num_str[-3:]

    a_value, b_value = int(a_str), int(b_str)
    if a_value == 0 and b_value != 0:
        return read3(b_str)
    elif a_value != 0 and b_value == 0:
        return '(' + read_123(a_str) + ')NGHÌN'

    return '(' + read_123(a_str) + ')NGHÌN, ' + read3(b_str)


# Hàm đọc 1 số có 7 hoặc 8 hoặc 9 chữ số
def read_789(num_str: str) -> str:
    if num_str == '000000000':
        return ''

    a_str = num_str[0: -6]
    b_str = num_str[-6:]

    a_value, b_value = int(a_str), int(b_str)
    if a_value == 0 and b_value != 0:
        return read_456(b_str)
    elif a_value != 0 and b_value == 0:
        return '[' + read_123(a_str) + ']TRIỆU'
    return '[' + read_123(a_str) + ']TRIỆU' + ', ' + read_456(b_str)


# Hàm đọc 1 số có nhiều hơn 9 chữ số
def read_more(num_str: str) -> str:
    a = num_str[0: -9]
    b = num_str[-9:]

    result = '{' + read(a) + '}TỈ'

    s = read_789(b)
    if s == '':
        return result

    return result + ', ' + s


# Hàm test các input đầu vào của chương trình
def test_program():
    test_nums = [
        '1', '12', '-121', '655', '1234', '100', '1000', '2551',
        '5 000 021', '95 035 679', '790 002 001',
        '1 000 000 000',
        '102 000 040 003',
        '32 645 789 515',
        '789123 456345921 879642900',
        '1 966777676 619784789 565459787 010080000 000000001'
    ]

    for input_num in test_nums:
        s = read(input_num)
        print(input_num, ':', s)


if __name__ == '__main__':
    # test_program() # Bỏ comment chỗ này để chạy các test có sẵng

    input_str = input('Nhập số của bạn (có thể chèn space để dễ đọc): ')
    user_input = read(input_str)
    print('Số của bạn nhập: ', input_str)
    print('Đọc tiếng việt: \n', user_input)
