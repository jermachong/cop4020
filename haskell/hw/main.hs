{--
    Jeremy Achong
    5124781
    Implementing pi approximations in Haskell
    Link: https://play.haskell.org/saved/jXqbmmZ1
--}

-- short pi function
shortpi::Double -- constant value to give simplepi approximation
shortpi = 4*(4 * atan( 1 / 5 ) - atan(1/239))


-- 4 times the sum of the equation using list comprehension from 1 to 200
-- takes in an int as the upperbound of summation and returns approximation in form of a Double
simplepi::Int -> Double
simplepi n = 
    -- list comprehension: [expression | variable <- range]
    -- fromIntegral converts between numeric types (Int to Double here) to satisfy type system
    4 * sum [fromIntegral ((-1)^(k+1)) / fromIntegral (2*k-1) | k<-[1..n]]
 
-- square root of 8 times the sum of 1 / 2*(k-1)^2
-- similar to simplepi, takes int as upper limit and returns approximation 
wellspi::Int->Double
wellspi n = 
    sqrt(8 * sum[fromIntegral 1 / (fromIntegral (2*k-1) * fromIntegral (2*k-1)) | k<-[1..n]])

-- takes in int as upper limit and returns approximation using euler formula
eulerpi::Int->Double
eulerpi n = 
    sqrt(6*sum[fromIntegral 1 / fromIntegral (k^2)| k<-[1..n]])


-- two functions to do wallis sequence
-- n is the limit of iterations, 1 is the first iteration of k
-- 1.0 (not 1) is used to ensure the accumulator starts as Double type, not Int
wallis::Int->Double
wallis n = wallishelp n 1 1.0

-- recursive function using accumulator pattern: carries running product through recursive calls
-- accumulator pattern avoids building up deferred operations (more memory efficient)
wallishelp::Int->Int->Double->Double
wallishelp n k product =
    if k > n then -- base case, finish calculation by multiplying by 2
        product * 2
    else -- recursive case: update accumulator (product) and recurse with k+1
        wallishelp n (k+1) (product * (fromIntegral (2*k) / fromIntegral (2*k-1)) * (fromIntegral (2*k) / fromIntegral (2*k+1)))

main::IO()
main = do
    let n = 200
    putStrLn("Short pi: \n" ++ show(shortpi)) -- single calculation, no n needed
    putStrLn ("Simple pi: \n" ++ show(simplepi n))
    putStrLn("Wells pi: \n" ++ show(wellspi n)) -- most precise for 200 iterations
    putStrLn("Euler pi: \n" ++show(eulerpi n))
    putStrLn("Wallis pi: \n" ++ show(wallis n)) 
