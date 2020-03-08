sumnum :: Int -> Int
sumnum 0 = 0
sumnum x = x `mod` 10 + sumnum (div x 10)