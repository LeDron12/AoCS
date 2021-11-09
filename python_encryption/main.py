import generator
import util
import time


def main():
    print(f'input 2 arguments: <amount_of_testf> <variant> \n'
          f'variant is 1 or 2 or 3 number that means encoding type')
    amount = int(input())
    variant = int(input())
    if variant < 1 or variant > 3:
        print('incorrect variant')
        return 0
    start_time = time.time()
    gen = generator.Generator()
    sort_keys = gen.genTests(amount, variant)
    printer = util.Util()
    printer.printTests(variant, sort_keys, amount)
    print("overall time spent: ~%s m.s." % (int((time.time() - start_time) * 1000)))


if __name__ == '__main__':
    main()
