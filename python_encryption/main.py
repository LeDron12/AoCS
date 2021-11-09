import generator
import util
import time


def main():
    print(f'input 2 arguments: \n'
          f'<amount_of_test> [1 ; inf)\n'
          f'<variant> [1 ; 3]')
    amount = int(input())
    variant = int(input())
    if variant < 1 or variant > 3:
        print('incorrect variant')
        return 0
    if amount < 1:
        print('incorrect amount')
        return 0
    start_time = time.time()
    gen = generator.Generator()
    sort_keys = gen.genTests(amount, variant)
    printer = util.Util()
    printer.printTests(variant, sort_keys, amount)
    print("overall time spent: ~%s m.s." % (int((time.time() - start_time) * 1000)))


if __name__ == '__main__':
    main()
