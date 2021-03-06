//
//  ViewController.m
//  PlayerTest
//
//  Created by 玉洋 on 2019/3/22.
//  Copyright © 2019 玉洋. All rights reserved.
//

#import "ViewController.h"
#import "IJKMoviePlayerViewController.h"
#import "IJKVRPlayerViewController.h"
#import "TriangleViewController.h"

@interface ViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) UITableView* tableView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style: UITableViewStylePlain];
    self.tableView.frame = self.view.bounds;
    [self.view addSubview:self.tableView];
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    
}


- (nonnull UITableViewCell *)tableView:(nonnull UITableView *)tableView cellForRowAtIndexPath:(nonnull NSIndexPath *)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    }
    if (indexPath.row == 0)
    {
        cell.textLabel.text = @"test1";
    } else if (indexPath.row == 1)
    {
        cell.textLabel.text = @"test1";
    } else if (indexPath.row == 2)
    {
        cell.textLabel.text = @"三角形";
    }
    
    return cell;
}

- (NSInteger)tableView:(nonnull UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 3;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row == 0)
    {
        NSURL   *url  = [NSURL URLWithString:@"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear1/prog_index.m3u8"];
        
        [self.navigationController presentViewController:[[IJKVideoViewController alloc] initWithURL:url] animated:YES completion:^{}];
    } else if (indexPath.row == 1)
    {
        NSURL   *url  = [NSURL URLWithString:@"http://devimages.apple.com.edgekey.net/streaming/examples/bipbop_4x3/gear1/prog_index.m3u8"];
        
        [self.navigationController presentViewController:[[IJKVRPlayerViewController alloc] initWithURL:url] animated:YES completion:^{}];
    } else if (indexPath.row == 2)
    {
        TriangleViewController* vc = [[TriangleViewController alloc] init];
        [self.navigationController pushViewController:vc animated:true];
    }
}

@end
