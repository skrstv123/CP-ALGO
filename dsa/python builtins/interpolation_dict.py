from bisect import bisect


# bisect returns the index of the element just greater than the input arg

class interpolation_dict(dict):

    """ interpolating dictionary
........when dict is being used as a lookup table for some function (like sine), an unknown key's value can be approximated using interpolation 
...."""

    def __missing__(self, key):

        # this function is called whenever a key is not found in the dictionary

        sortedKey = sorted(self.keys())

        pos = bisect(sortedKey, key)

        if pos == 0 or pos == len(sortedKey):
            raise keyError('cant interpolate')
        (lkey, rkey) = (sortedKey[pos - 1], sortedKey[pos])

        # using y = mx + c

        m = (-self[lkey] + self[rkey]) / (rkey - lkey)
        self[key] = val = m * (key - lkey) + self[lkey]

        return val



			