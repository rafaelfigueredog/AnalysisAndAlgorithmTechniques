import random

def sortingDataFrameTime(type=0):

    performance = {"N0": [], "MergeSort Time": [], "InsertionSort Time": []}

    N = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    if (type != 1 and type != 2):
        N.append(120)
        N.append(130)
        N.append(150)

    DataFramesDistribuition = []

    for n0 in N:
        distribution = {"N0": [], "MergeSort Time": [], "InsertionSort Time": []}
        for i in range(10):

            distribution['N0'].append(n0)
            array1 = []

            if (type == 0):
                array1 = Rand(0, 100, n0)

            elif (type == 1):
                array1 = array1 = [int(x) for x in range(n0, 0, -1)]

            else:
                array1 = [u for u in range(0, n0, 1)]
                for k in range(n0//3):
                    while (1):
                        i = random.randint(0, n0-1)
                        j = random.randint(0, n0-1)
                        if (i != j):
                            array1[j], array1[i] = array1[i], array1[j]
                            break

            array2 = array1.copy()

            start = timeit.default_timer()
            mergeSort(array1)
            tms = timeit.default_timer() - start
            distribution["MergeSort Time"].append(tms)

            start = timeit.default_timer()
            insertionSort(array2)
            tis = timeit.default_timer() - start
            distribution["InsertionSort Time"].append(tis)

        DataFramesDistribuition.append(pd.DataFrame(distribution))

    return DataFramesDistribuition
