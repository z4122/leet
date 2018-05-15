int cmp(const void *a,const void *b)
{
	char *num1=*(char**)a;
	char *num2=*(char**)b;
	char str1[65]={0};
	char str2[65]={0};
	strcat(str1,num1);
	strcat(str1,num2);
	strcat(str2,num2);
	strcat(str2,num1);
	return -strcmp(str1,str2);
}
char* largestNumber(int* nums, int numsSize) {
    char *nums2[numsSize];
	int i;
	for(i=0;i<numsSize;i++){
		nums2[i]=(char*)malloc(32*sizeof(char));
	}
	for(i=0;i<numsSize;i++){
		sprintf(nums2[i],"%d",nums[i]);
	}

	qsort(nums2,numsSize,sizeof(char*),cmp);
	// for(i=0;i<numsSize;i++){
	// 	puts(nums2[i]);
	// }
	char *result=(char*)malloc(32*numsSize*sizeof(char));
    result[0]=0;
	for(i=0;i<numsSize;i++){
		strcat(result,nums2[i]);
	}
	if(result[0]=='0')
		result[1]=0;
	return result;
    
}
