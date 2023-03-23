def main():
    n = int(input())
    while n:
        n -= 1
        expression = input()
        if expression[0] == "P":
            print("skipped")
            continue
        num1 = int(expression[:expression.find("+")])
        num2 = int(expression[expression.find("+") + 1:])
        print(num1 + num2)


if __name__ == '__main__':
    main()
    